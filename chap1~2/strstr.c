#include <stdio.h>
#include <string.h>

int main() {
    const char *stringA = "Hello, World!";
    const char *stringB = "x";

    char *result = strstr(stringA, stringB);

    if (result != NULL) {
        printf("'%s' �b '%s' ������m�G%ld\n", stringB, stringA, result - stringA);
    } else {
        printf("'%s' ���O '%s' ���l��\n", stringB, stringA);
        if (result ==NULL){
        	printf("yess");
		}
    }

    return 0;
}

