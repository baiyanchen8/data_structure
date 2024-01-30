#include <stdio.h>

// �w�q�`�I���c
struct node {
    int data;
    struct node* next;
};

struct node* pool;

// �M�Ÿ`�I���禡
void erase(struct node* A) {
    struct node* tmp;
    while (A) {
        tmp = A;
        A = A->next;
        // �M���䤤���e
        tmp->data=-1;
        tmp->next = pool;
        pool = tmp;
    }
}

// ���o�s�`�I���禡
struct node* getnode() {
    if (pool) {
        struct node* tmp;
        tmp = pool;
        pool = pool->next;
        tmp->next = NULL;
        return tmp;
    } else {
        struct node* tmp;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->next=NULL;
        return tmp;
    }
}

// ���եΪ��禡
void printList(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // ���ղM�Ÿ`�I���禡
    struct node* head = getnode();
    head->data = 1;

    struct node* node2 = getnode();
    node2->data = 2;
    head->next = node2;

    struct node* node3 = getnode();
    node3->data = 3;
    node2->next = node3;

    printf("��l���: ");
    printList(head);

    erase(head);
    head=NULL;
    printf("�M�ū����: ");
    printList(head);

	printList(pool);
    return 0;
}

