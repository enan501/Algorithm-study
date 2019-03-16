#include<stdio.h>

int arr[100];
int n = 0;
unsigned long long dp[21][100];
unsigned long long dfs(bool opt, int i, int num)
{
	unsigned long long ret = 0;
	if (opt)
	{
		num += arr[i];
		if (num > 20)
			return 0;
	}
	else
	{
		num -= arr[i];
		if (num < 0)
			return 0;
	}
	if (i == n - 2)
	{
		if (num == arr[n - 1])
			return 1; 
		else
			return 0;
	}
	if (dp[num][i] > 0) return dp[num][i];
	ret += dfs(true, i + 1, num);
	ret += dfs(false, i + 1, num);
	return dp[num][i] = ret;
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%llu",dfs(true, 0, 0));
	return 0;
}