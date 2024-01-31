#include <stdio.h>

// �w�q�`�I���c
struct node {
    int data;
    struct node* next;
};

// �p�������ת��禡
int countlength(struct node* A) {
    if (!A) return 0;  // �p�G����šA���׬�0
    struct node* tmp;
    int c = 1;  // ��l���׬�1�A�]�� A �s�b
    for (tmp = A->next; tmp != NULL && A != tmp; tmp = tmp->next) {
        c++;
    }
    return c;
}

// ���եΪ��禡
void printList(struct node* head) {
	struct node * tmp = head;
	printf("%d ", head->data);
	head=head ->next;
    while (head!=tmp&&head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // ���խp�������ת��禡
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;

    struct node* node2 = (struct node*)malloc(sizeof(struct node));
    node2->data = 2;
    head->next = node2;

    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    node3->data = 3;
    node2->next = node3;
	node3->next=NULL;
    printf("��l���: ");
    printList(head);

    int length = countlength(head);
    
    printf("������: %d\n", length);

    return 0;
}

