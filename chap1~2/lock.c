#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int lock = 0;  // ��l���A��O�Ŷ���

void critical_section(int i) {
    // �o�̩�m�{�ɰϪ��{���X
    printf("%d\n", i);
}

void* thread_function(void* arg) {
    int i = *((int*)arg);  // �N arg �ഫ�����
    while (lock != 0);  // �۱۪�����O�Ŷ���
    lock = 1;  // ���o��
    critical_section(i);  // �i�J�{�ɰ�
    lock = 0;  // ������

    pthread_exit(NULL);
}

int main() {
    const int num_threads = 2;
    pthread_t threads[num_threads];
    int i;

    // �Ыب�Ӱ����
    for (i = 0; i < num_threads; ++i) {
        if (pthread_create(&threads[i], NULL, thread_function, &i) != 0) {
            fprintf(stderr, "������Ыإ���\n");
            exit(EXIT_FAILURE);
        }
    }

    // ���ݰ��������
    for (i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

