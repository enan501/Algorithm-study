#include <stdio.h>
int dp[100000][2];
int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	dp[0][0] = 1;
	dp[0][1] = 2;
	for (int i = 0; i < n; i++)
	{
		dp[i + 1][0] = (dp[i][0] + dp[i][1]) % 9901;
		dp[i + 1][1] = (dp[i][0] * 2 + dp[i][1]) % 9901;
	}
	printf("%d", (dp[n - 1][0] + dp[n - 1][1]) % 9901);
	scanf_s("%d", &n);
	return 0;
}