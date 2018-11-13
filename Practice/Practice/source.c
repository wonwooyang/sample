#include <stdio.h>

void main() {
	/*
	int a[] = { 0,1,2,3,4,5 };
	int *p = a;

	printf_s("%2d, %2d\n", *(p + 1), *(p + 4));
	printf_s("%2d, %2d\n", p[0], p[4]);
	printf_s("");
	*/

	int ary[3][3] = { 1,2,3,
						4,5,6,
						7,8,9 };
	int(*ptr)[3] = ary;

	printf("\n\n");
	printf("1 - %2d, %2d\n", **ary, **ptr++);
	printf("2 - %2d, %2d\n", **(ary+1), **(ptr++));
	printf("\n\n");

	ptr = ary;

	printf("1 - %2d, %2d\n", *(ary[1] + 1), *(ptr[1] + 1));
	printf("2 - %2d, %2d\n", *(*(ary + 1) + 3), *(*(ptr+1) +1));

}