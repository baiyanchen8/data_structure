#include <stdio.h>
#include <stdlib.h>

// �إߵ������Y
void equivalence(int A[9][2], int A1[12]) {
    int i;
    int class_num = 0;

    // ��l�� A1 �}�C
    for (i = 0; i < 12; i++) {
        A1[i] = -1;
    }

    // �M���������Y�}�C A
    for (i = 0; i < 9; i++) {
        // �p�G��Ӹ`�I���٨S���Q����
        if (A1[A[i][0]] == -1 && A1[A[i][1]] == -1) {
            A1[A[i][0]] = class_num;
            A1[A[i][1]] = class_num++;
        } else if (A1[A[i][0]] == -1 && A1[A[i][1]] != -1) {
            // �p�G A[i][0] �٨S���Q�����A�� A[i][1] �w�g�Q����
            A1[A[i][0]] = A1[A[i][1]];
        } else if (A1[A[i][0]] != -1 && A1[A[i][1]] == -1) {
            // �p�G A[i][0] �w�g�Q�����A�� A[i][1] �٨S���Q����
            A1[A[i][1]] = A1[A[i][0]];
        } else if (A1[A[i][0]] != -1 && A1[A[i][1]] != -1) {
            // �p�G��Ӹ`�I���w�g�Q�����A���������P�A�h�Τ@����
            if (A1[A[i][0]] != A1[A[i][1]]) {
                int j;
                for (j = 0; j < 12; j++) {
                    if (A1[j] == A1[A[i][0]]) {
                        A1[j] = A1[A[i][1]];
                    }
                }
            }
        }
    }
}

int main() {
    // ��J���������Y�}�C
    int input[12][2] = {{0, 4}, {3, 1}, {6, 10}, {8, 9}, {7, 4}, {6, 8}, {3, 5}, {2, 11}, {11, 0}};
    int un[12];

    // �I�s equivalence �禡
    equivalence(input, un);

    // ��X���G
    int i;
    for (i = 0; i < 12; i++) {
        printf("%d %d \n", i, un[i]);
    }

    return 0;
}

