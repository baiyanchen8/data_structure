#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node *head;
struct node *tail;

void enqueue(int data);
int dequeue();

int main() {
    head = NULL;
    tail = NULL;
    
    // �b�o�̩I�s enqueue �M dequeue �禡�i�����
    enqueue(1);
    enqueue(2);
    enqueue(3);
    int dequeuedValue = dequeue();
	while (dequeuedValue!=-1){
		
	    if (dequeuedValue != -1) {
	        printf("�q��C�����X�G%d\n", dequeuedValue);
	    } else {
	        printf("��C�O�Ū��A�L�k���X�C\n");
	    }
	    dequeuedValue = dequeue();
	}
    

    return 0;
}

void enqueue(int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if (tail == NULL) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}

int dequeue() {
    struct node *tmp;
    if (head == NULL) {
        return -1;
    } else {
        tmp = head->next;
        int dequeuedValue = head->data;
        free(head);
        head = tmp;
        if (head == NULL) {
            tail = NULL;
        }
        return dequeuedValue;
    }
}

