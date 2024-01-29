#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    struct PolyNode* next;
    int expon;
    int coef;
};

struct PolyNode* add(struct PolyNode* A, struct PolyNode* B) {
    if (!A) {
        return B;
    } else if (!B) {
        return A;
    }

    struct PolyNode* tmpA = A;
    struct PolyNode* tmpB = B;
    struct PolyNode* ans = NULL;

    while (tmpA || tmpB) {
        struct PolyNode* tmp = 
			(struct PolyNode*)malloc(sizeof(struct PolyNode));
        tmp->next = ans;

        if (!tmpA) {
            tmp->expon = tmpB->expon;
            tmp->coef = tmpB->coef;
            tmpB = tmpB->next;
        } else if (!tmpB) {
            tmp->expon = tmpA->expon;
            tmp->coef = tmpA->coef;
            tmpA = tmpA->next;
        } else {
            if (tmpA->expon == tmpB->expon) {
                tmp->expon = tmpA->expon;
                tmp->coef = tmpA->coef + tmpB->coef;
                tmpA = tmpA->next;
                tmpB = tmpB->next;
            } else if (tmpA->expon > tmpB->expon) {
                tmp->expon = tmpA->expon;
                tmp->coef = tmpA->coef;
                tmpA = tmpA->next;
            } else {
                tmp->expon = tmpB->expon;
                tmp->coef = tmpB->coef;
                tmpB = tmpB->next;
            }
        }

        ans = tmp;
    }

    return ans;
}


void printPoly(struct PolyNode* poly) {
    while (poly) {
        printf("%dx^%d ", poly->coef, poly->expon);
        if (poly->next) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    // �إߦh���� A: 3x^3 + 2x^2 + 5x^1
    struct PolyNode* polyA = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyA->expon = 3;
    polyA->coef = 3;
    polyA->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyA->next->expon = 2;
    polyA->next->coef = 2;
    polyA->next->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyA->next->next->expon = 1;
    polyA->next->next->coef = 5;
    polyA->next->next->next = NULL;

    // �إߦh���� B: 2x^3 + 4x^1 + 1x^0
    struct PolyNode* polyB = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyB->expon = 3;
    polyB->coef = 2;
    polyB->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyB->next->expon = 2;
    polyB->next->coef = 4;
    polyB->next->next = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    polyB->next->next->expon = 1;
    polyB->next->next->coef = 1;
    polyB->next->next->next = NULL;

    // ��X��l�h����
    printf("�h���� A: ");
    printPoly(polyA);
    printf("�h���� B: ");
    printPoly(polyB);

    // �h�����ۥ[
    struct PolyNode* result = add(polyA, polyB);

    // ��X�ۥ[���G
    printf("�ۥ[���G: ");
    printPoly(result);

    // ����O����
    free(polyA);
    free(polyB);
    free(result);

    return 0;
}

