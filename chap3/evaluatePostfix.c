#include <stdio.h>
#include <stdlib.h>

// 定義堆疊結構
typedef struct {
    int top;
    int* array;
} Stack;

// 初始化堆疊
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// 檢查堆疊是否滿了
int isFull(Stack* stack, int capacity) {
    return stack->top == capacity - 1;
}

// 檢查堆疊是否為空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 把元素壓入堆疊
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// 從堆疊中彈出元素
int pop(Stack* stack) {
    return stack->array[stack->top--];
}

// 計算後置表達式
int evaluatePostfixWithWhitespace(char* exp) {
    int i;
    Stack* stack = createStack(strlen(exp));
    if (!stack)
        return -1;  // 異常狀況

    for (i = 0; exp[i]; ++i) {
        // 如果是空白，跳過
        if (isspace(exp[i]))
            continue;

        // 如果是數字，則壓入堆疊
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                ++i;
            }
            --i;  // 回退一格，因為迴圈會再自動加一
            push(stack, num);
        } else {
            // 如果是運算子，則從堆疊中彈出兩個數字進行計算，再將結果壓入堆疊
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
    return pop(stack);  // 堆疊頂部的值即為計算結果
}

// 測試修正的後置表達式計算
int main() {
    char *exp=malloc(20);
    printf("rule \n1. 使用後置\n2. 使用空白區分不同數字\n   ex : 12 3+7* -> (12+3)*7\n3. input exit to exit\n");
    while(strncmp(exp,"exit",4)){
    	gets(exp);
    	if (strncmp(exp,"exit",4))
    		printf("後置表達式 %s 的計算結果是 %d\n", exp, evaluatePostfixWithWhitespace(exp));
	}
    
    return 0;
}
