#include <stdio.h>
using namespace std;
int dp[1000][2];
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	dp[0][0] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		dp[i + 1][0] = (dp[i][0] + dp[i][1]) % 10007;
		dp[i + 1][1] = dp[i][0] % 10007;
	}
	printf("%d", (dp[n - 1][0] + dp[n - 1][1]) % 10007);
	return 0;
}