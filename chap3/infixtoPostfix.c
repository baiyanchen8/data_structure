#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �w???��
typedef struct {
    int top;
    char* array;
} Stack;

// ��l��?
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// ?�d?�O�_?
int isFull(Stack* stack, int capacity) {
    return stack->top == capacity - 1;
}

// ?�d?�O�_?��
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ?����?�J?
void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// ??��?�X����
char pop(Stack* stack) {
    return stack->array[stack->top--];
}

// ?��??����
char peek(Stack* stack) {
    return stack->array[stack->top];
}

// �P??��Ū�ɬ��?
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;  // ?�_��L�r�šA�p�A?���Aɬ��??0
    }
}

// ��?��?��?�Z?��?��
char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    Stack* stack = createStack(len);

    for (i = 0, j = 0; i < len; ++i) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);  
        } else { 
        	postfix[j++]=' ';
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // ??���ѧE���ާ@��?�X
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';  // �b�r�Ŧ꥽���K�[�Ŧr��
    return postfix;
}

int main() {
    char* exp = (char*)malloc(20 * sizeof(char));

    while (strncmp(exp, "exit", 4)) {
        gets(exp);
        if (strncmp(exp, "exit", 4)) {
            char* postfix = infixToPostfix(exp);
            printf("��m��F���G%s\n", postfix);
            free(postfix);  // ?��??���t��?�s
        }
    }

    free(exp);  // ?��??���t��?�s
    return 0;
}

