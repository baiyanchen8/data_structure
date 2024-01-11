#include <stdio.h>
#include <stdlib.h>

// �w�q���|���c
typedef struct {
    int top;
    int* array;
} Stack;

// ��l�ư��|
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// �ˬd���|�O�_���F
int isFull(Stack* stack, int capacity) {
    return stack->top == capacity - 1;
}

// �ˬd���|�O�_����
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// �⤸�����J���|
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// �q���|���u�X����
int pop(Stack* stack) {
    return stack->array[stack->top--];
}

// �p���m��F��
int evaluatePostfixWithWhitespace(char* exp) {
    int i;
    Stack* stack = createStack(strlen(exp));
    if (!stack)
        return -1;  // ���`���p

    for (i = 0; exp[i]; ++i) {
        // �p�G�O�ťաA���L
        if (isspace(exp[i]))
            continue;

        // �p�G�O�Ʀr�A�h���J���|
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                ++i;
            }
            --i;  // �^�h�@��A�]���j��|�A�۰ʥ[�@
            push(stack, num);
        } else {
            // �p�G�O�B��l�A�h�q���|���u�X��ӼƦr�i��p��A�A�N���G���J���|
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);  // ���|�������ȧY���p�⵲�G
}

// ���խץ�����m��F���p��
int main() {
    char *exp=malloc(20);
    printf("rule \n1. �ϥΫ�m\n2. �ϥΪťհϤ����P�Ʀr\n   ex : 12 3+7* -> (12+3)*7\n3. input exit to exit\n");
    while(strncmp(exp,"exit",4)){
    	gets(exp);
    	if (strncmp(exp,"exit",4))
    		printf("��m��F�� %s ���p�⵲�G�O %d\n", exp, evaluatePostfixWithWhitespace(exp));
	}
    
    return 0;
}
