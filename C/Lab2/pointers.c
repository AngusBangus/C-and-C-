#include <stdio.h>


int main(){
	int x = 0, y = 0, *px, *py;
	int arr[10];
	arr[0] = 1, arr[1] = 2, arr[2] = 3;
	px = &x;
	py = &y;
	printf("address for x is ");
	printf("%p\n", &x);
	printf("address for y is ");
	printf("%p\n", &y);
	printf("address for px is ");

	printf("%p\n", px);

	printf("address for py is ");

	printf("%p\n", py);

	for(int i = 0; i < 10; i++){
		
		*arr = *(arr + i);

		printf("%d\n", *arr);
	}

	return 0;
}