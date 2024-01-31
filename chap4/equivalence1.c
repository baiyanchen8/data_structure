#include <stdio.h>
#include <stdlib.h>

// �w�q�`�I���c
struct node {
    int data;
    struct node* next;
};

// �إߵ������Y
void equivalence(int A[9][2], struct node* A1[]) {
    // ��l�Ƹ`�I�}�C
    int i;
    for (i = 0; i < 12; i++) {
        A1[i] = NULL;
    }

    // �Ыص������Y���쵲��C
    for (i = 0; i < 9; i++) {
        struct node *tmp;

        // �N A[i][0] �P A[i][1] �[�J�������쵲��C��
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->next = A1[A[i][0]];
        tmp->data = A[i][1];
        A1[A[i][0]] = tmp;

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->next = A1[A[i][1]];
        tmp->data = A[i][0];
        A1[A[i][1]] = tmp;
    }
}


// �N�����[�J�}�C�A�קK����
int add(int *ans, int *anssize, int addnum) {
    int i;
    for (i = 0; i < *anssize - 1; i++) {
        if (addnum == ans[i]) return -1;
    }
    (*anssize) += 1;
    ans = (int *)realloc(ans, (*anssize) * sizeof(int));
    ans[(*anssize) - 2] = addnum;
    return 0;
}


// �ϥβ`���u���j�M��M�������Y��������
void find(int findi, struct node *A1[], int *ans, int *anssize) {
    if (!A1[findi]) {
        return;
    }
    struct node *tmp;
    int i = 1;  // ��l�� i �� 1
    for (tmp = A1[findi]; tmp->next!=NULL; tmp = tmp->next) {
        printf("%d: %d %d\n", i++, tmp->data,anssize[0]);  // �ץ��G�[�J i++
        int t = add(ans, anssize, tmp->data);
        if (t != -1) find(tmp->data, A1, ans, anssize);
    }
    if (tmp!=NULL){
		int t = add(ans, anssize, tmp->data);
    	if (t != -1) find(tmp->data, A1, ans, anssize);
	}
	printf("%d finish \n",findi);
}

int main() {
    // ��J���������Y�}�C
    int input[12][2] = {{0, 4}, {3, 1}, {6, 10}, {8, 9}, {7, 4}, {6, 8}, {3, 5}, {2, 11}, {11, 0}};
    struct node *seq[12];
    equivalence(input, seq);

    // �ʺA�t�m�O����s�񵲪G
    int *ans = (int *)malloc(sizeof(int));
    int anssize = 1;
    
    // �M�䵥�����Y��������
    find(6, seq, ans, &anssize);
    
    // ��X���G
    int i;
    for (i = 0; i < anssize - 1; i++) {
        printf("%d ", ans[i]);
    }

    // ����ʺA�t�m���O����
    for (i = 0; i < 12; i++) {
        struct node *current = seq[i];
        while (current != NULL) {
            struct node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(ans);

    return 0;
}

