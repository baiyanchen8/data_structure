#include <stdio.h>
#include <stdlib.h>

int main() {
    // �ϥ�malloc���t�@?�㫬??
    int *arr = (int *)malloc(5 * sizeof(int));
    int j;
    for(j=0;j<5;j++){
	
		*(arr+j)=0;
	}
	*arr=1;
    if (arr == NULL) {
        fprintf(stderr, "?�s���t��?\n");
        return 1;
    }

   
    int *new_arr = (int *)realloc(arr, 10 * sizeof(int));

    if (new_arr == NULL) {
        fprintf(stderr, "���s���t�s��\n");
        free(arr);  
        return 1;
    }
	for(j=0;j<10;j++){
	
		printf("%d  ",*(new_arr+j));
	}
	printf("\n");
    // �b?���i�H�ϥ�new_arr

    // �̦Z?��?�s
    free(new_arr);

    return 0;
}

