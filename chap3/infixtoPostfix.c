#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ﹚???疼
typedef struct {
    int top;
    char* array;
} Stack;

// ﹍て?
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// ?琩?琌?
int isFull(Stack* stack, int capacity) {
    return stack->top == capacity - 1;
}

// ?琩?琌?
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ?じ??
void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// ??い?じ
char pop(Stack* stack) {
    return stack->array[stack->top--];
}

// ???じ
char peek(Stack* stack) {
    return stack->array[stack->top];
}

// ??衡才涩?
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;  // ?ㄤ才珹?单涩??0
    }
}

// い??Α???Α
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

    // ??い逞巨才?
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';  // 才﹃ソЮ睰才
    return postfix;
}

int main() {
    char* exp = (char*)malloc(20 * sizeof(char));

    while (strncmp(exp, "exit", 4)) {
        gets(exp);
        if (strncmp(exp, "exit", 4)) {
            char* postfix = infixToPostfix(exp);
            printf("竚笷Α%s\n", postfix);
            free(postfix);  // ???だ皌?
        }
    }

    free(exp);  // ???だ皌?
    return 0;
}

