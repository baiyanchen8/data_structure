#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max 1001
struct poly{
	int degree;//�̰��ż�
	float coef[max];//�C�Ū��Y��
};
int main(){
	// use time to genrate rand seed
    srand(time(NULL));

    struct poly A,B;
	A.degree= rand() % max;
	B.degree= rand() % max;
	int i;
	for (i=0;i<A.degree||i<B.degree;i++){
		if (i<A.degree){
			A.coef[i]=
		}
	}

	return 0;
}
