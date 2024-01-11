#include <stdio.h>
#include <stdlib.h>

// �w�q��C���c
struct queue {
    int *arr;   // �x�s�������}�C
    int head;   // ��C�Y
    int tail;   // ��C��
    int count;  // ��C�e�q
};

// ��l�Ʀ�C�A�ë��w��l�e�q
void Q_init(struct queue *Q, int capacity) {
    Q->arr = (int *)malloc(capacity * sizeof(int));  // ���t�O���鵹�}�C
    Q->head = 0;
    Q->tail = 0;
    Q->count = capacity;
}

// ���s�t�m��C�e�q
void Q_resize(struct queue *Q, int new_capacity) {
    Q->arr = (int *)realloc(Q->arr, new_capacity * sizeof(int));  // ���s�t�m�O����
    Q->count = new_capacity;
}

// �J��C
void enQ(struct queue *Q, int num) {
    if ((Q->tail + 1) % Q->count == Q->head) {
        // ��C�w���A�ݭn�X�R�e�q
        int new_capacity = Q->count * 2;
        Q_resize(Q, new_capacity);
    }

    Q->tail = (Q->tail + 1) % Q->count;
    Q->arr[Q->tail - 1] = num;
}

// �X��C
int deQ(struct queue *Q) {
    if (Q->head == Q->tail) {
        // ��C���šA��^�S��ȡ]�o�̰��]��C�s�x������������ơ^
        return -1;
    }

    int re = Q->arr[Q->head];
    Q->head = (Q->head + 1) % Q->count;

    // �ˬd�O�_�i�H�Y��e�q
    if (Q->count > 20 && (Q->tail + 1) % Q->count <= Q->head) {
        int new_capacity = Q->count / 2;
        Q_resize(Q, new_capacity);
    }

    return re;
}

// �����C���O����
void Q_free(struct queue *Q) {
    free(Q->arr);
}

// ���յ{���X
int main() {
    struct queue myQueue;
    Q_init(&myQueue, 20);  // ��l�e�q�� 20
	int i;
    // �N�Ʀr 1 �� 25 ��J��C
    for (i = 1; i <= 240; i++) {
        enQ(&myQueue, i);
    }

    // �X��C�æL�X
    for ( i = 0; i < 240; i++) {
        printf("%d ", deQ(&myQueue));
    }

    // �����C���O����
    Q_free(&myQueue);

    return 0;
}

