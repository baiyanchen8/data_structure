#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//int main(int k,char *argv[]) {
//	int ar[]={1,2,3,4};
//	int b = &ar[3];
//	printf("%d\n",b);
//	return 0;
//	
//}
int main(){
    int a=0;
    int *addr_a=&a;//�b�R�W��}�ܼƮɥ����b�e���[*
    printf("%d",*addr_a);
}
