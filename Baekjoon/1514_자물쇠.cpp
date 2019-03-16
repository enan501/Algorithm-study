#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[101],pwd[101],dp[101][10][10][10],n;

int func(int i, int a, int b, int c)
{
	if (i == n) return 0;
	if (dp[i][a][b][c] != -1) return dp[i][a][b][c];
	dp[i][a][b][c] = 987654321;
	if ((a + 10 + arr[i])%10 == pwd[i]) dp[i][a][b][c] = func(i + 1, b, c, 0);
	for (int j = -3; j < 4; j++)
	{
			dp[i][a][b][c] = min(dp[i][a][b][c], 1 + func(i, (a + j + 10) % 10, b, c));
			dp[i][a][b][c] = min(dp[i][a][b][c], 1 + func(i, (a + j + 10) % 10, (b + j + 10) % 10, c));
			dp[i][a][b][c] = min(dp[i][a][b][c], 1 + func(i, (a + j + 10) % 10, (b + j + 10) % 10, (c + j + 10) % 10));
	}
	return dp[i][a][b][c];
}
int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%1d", &arr[i]);
	for (int i = 0; i < n; i++)
		scanf_s("%1d", &pwd[i]);
	printf("%d", func(0, 0, 0, 0));
	return 0;
}