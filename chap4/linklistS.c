#include <stdio.h>
#include <stdlib.h>

// �w�q�`�I���c
struct node {
	struct node *next;
	int data;
};

// �w�q�����ܼ� stack�A�ΨӪ�ܰ��|����
struct node *stack;

// �禡�쫬�ŧi
void push(int data);
int pop();

// �D�禡
int main() {
	stack = NULL; // ��l�ư��|�A�]����
	push(1);
	push(2);
	push(3);
	printf("%d \n",pop());
	printf("%d \n",pop());
	printf("%d \n",pop());
	printf("%d \n",pop());
	return 0;
}

// push �禡�A�N������J���|
void push(int data) {
	if (!stack) {
		// �p�G���|���šA�h�إ߷s�`�I�@�����|����
		stack = (struct node *)malloc(sizeof(struct node));
		stack->data = data;
		stack->next = NULL;
	} else {
		// �p�G���|�D�šA�h�إ߷s�`�I�A�ñN��s������|����
		struct node *tmp;
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->data = data;
		tmp->next = stack;
		stack = tmp;
	}
}

// pop �禡�A�q���|���u�X���
int pop() {
	if (!stack) {
		// �p�G���|���šA�^�� NULL�]��ܵL�k�u�X�^
		return NULL;
	} else {
		// �p�G���|�D�šA���o���ݸ`�I����ơA�ñN���ݸ`�I����
		struct node *tmp = stack->next;
		int t1 = stack->data;
		free(stack);
		stack = tmp;
		return t1;
	}
}

