
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int data;
};
struct node* connect(struct node* P1, struct node* P2) {
    if (!P1) return P2;
    if (!P2) return P1;

    struct node* tmp;
    for (tmp = P1; tmp->next != NULL; tmp = tmp->next);

    tmp->next = P2;
    return P1;
}

void printlink(struct node* poly) {
    while (poly) {
        printf("%d ", poly->data);
        poly = poly->next;
    }
    printf("\n");
}
// ��ƥΩ�ͦ��]�t�@�� link list �����c
struct node* generateLinkedList(int size) {
    struct node* head = NULL;
    struct node* current = NULL;

    // �ͦ� link list�A�]�t�Ʀr 1 �� size
    int i;
    for (i = 1; i <= size; ++i) {
        // �Ыطs�`�I
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (!newNode) {
            // �O������t���ѡA�B�z���~
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        // �]�w�`�I�����
        newNode->data = i;
        newNode->next = NULL;

        // �N�s�`�I�[�J link list
        if (!head) {
            // �Y link list ���šA�N�s�`�I�]���Y�`�I
            head = newNode;
            current = head;
        } else {
            // �Y link list �����šA�N�s�`�I�s����ثe�`�I���᭱
            current->next = newNode;
            current = newNode;
        }
    }

    // ��^ link list ���Y����
    return head;
}
int main (){
	struct node * tmp =generateLinkedList(3);
	printlink(tmp);
	struct node * tmp1 =generateLinkedList(5);
	printlink(tmp1);
	printlink(connect(tmp,tmp1));
}
