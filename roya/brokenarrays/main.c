#include <stdio.h>

int main(int argc, char** argv)
{
	char test1[16] = {14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	char test2[4] = {3,4,3,4};
	char test3[4] = {7,9,7,9};

	int i = 0;
	printf("The following memory dump contains the literal ':<:<6767ABCDEFGHIJKLMNOP'. This is our three arrays.\n");
	for (i = -100; i < 100; i++)
		printf("%c", (int)test1[i]+51);

	return 0;
}
