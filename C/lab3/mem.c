
#include <stdio.h>
#include <stdlib.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;

	printf("address of ptr %p \n", &ptr);
	printf("address of handle %p \n", &handle);
	printf("address of num %p \n", &num);




	return 0;
} 

