#include<iostream>
using namespace std;
int n, arr[101][101];
long long int dp[101][101];
long long int dfs(int x, int y)
{
	long long int s = 0;
	if (y + arr[y][x] < n)
	{
		if (dp[y + arr[y][x]][x] != -1) s += dp[y + arr[y][x]][x];
		else if(arr[y][x]) s += dfs(x, y + arr[y][x]);
	}
	if (x + arr[y][x] < n)
	{
		if (dp[y][x + arr[y][x]] != -1) s += dp[y][x + arr[y][x]];
		else if(arr[y][x]) s += dfs(x + arr[y][x], y);
	}
	return dp[y][x] = s;
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	dp[n-1][n-1] = 1;
	dfs(0, 0);
	cout << dp[0][0];
	return 0;
}