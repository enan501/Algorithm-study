#include<stdio.h>
int n, a[1000001], b, c;
long long int s;
int main(void)
{
	scanf_s("%d",&n);
	for(int i=0;i<n; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d %d", &b, &c);
	s = n;
	for (int i = 0; i < n; i++)
		if(a[i]-b > 0) s += (a[i] - b + c - 1) / c;
	printf("%lld", s);
	return 0;
}