#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define n 4

volatile bool waiting[n];
volatile bool lock = false;

// �ϥ� Test-and-Set ��{����������
bool test_and_set(bool *target) {
    bool previous = *target;
    *target = true;
    return previous;
}

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
	int i=0;
    do {
        waiting[thread_id] = true;
		i++;
        while (waiting[thread_id] == true&& test_and_set(&lock)) {
            // ����������
        }

        waiting[thread_id] = false;

        // �i�J�{�ɰ�
        printf("����� %d �i�J�{�ɰ�\n", thread_id);
        // �b�o�̩�m�{�ɰϪ��{���X
//        sleep(1);  // �����{�ɰϰ���ɶ�
        printf("����� %d ���}�{�ɰ�\n", thread_id);

        int j = (thread_id + 1) % n;

        // �M��U�@�ӵ��ݪ������
        while (j != thread_id && waiting[j]==false) {
            j = (j + 1) % n;
        }

        if (j == thread_id) {
            // �S�����ݪ�������A������
            lock = false;
        } else {
            // �q���U�@�ӵ��ݪ�������i�J�{�ɰ�
            waiting[j] = false;
        }

    } while (i<10);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[n];
    int thread_ids[n];
    int i;

    // ��l�Ƶ��ݪ��A
    for (i = 0; i < n; ++i) {
        waiting[i] = false;
    }

    // �Ы� n �Ӱ����
    for (i = 0; i < n; ++i) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            fprintf(stderr, "������Ыإ���\n");
            return -1;
        }
    }
    // �D��������ݩҦ����������
    for (i = 0; i < n; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

