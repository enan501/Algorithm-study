#include <stdio.h>
#include <string.h>
int dp[1001][10];
int func(int n, int d) //n(자리수)를 하나씩 줄이며 재귀, d는 해당 자리의 숫자
{
	if (n == 0)
		return 1;
	if (dp[n][d] > 0)
		return dp[n][d];
	for (int i = d; i < 10; i++)
		dp[n][d] += func(n - 1, i)%10007;
	return dp[n][d] %= 10007;
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	printf("%d", func(n, 0));
	return 0;
}