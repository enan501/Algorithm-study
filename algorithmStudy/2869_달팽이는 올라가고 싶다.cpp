#include<stdio.h>
long long int a, b, v;
int main(void)
{
	scanf_s("%d %d %d", &a, &b, &v);
	printf("%d", (v - b + (a-b) -1 ) / (a - b));
	return 0;
}