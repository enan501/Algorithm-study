#include<iostream>
using namespace std;
int m, n, arr[502][502], dp[502][502], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int dfs(int x, int y)
{
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		if (arr[y + dy[i]][x + dx[i]] > arr[y][x])
		{
			if (dp[y + dy[i]][x + dx[i]] == -1) dp[y][x] += dfs(x + dx[i], y + dy[i]);
			else dp[y][x] += dp[y + dy[i]][x + dx[i]];
		}
	}
	return dp[y][x];
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	dp[1][1] = 1;
	dfs(n, m);
	cout << dp[m][n];
}