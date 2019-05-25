#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501], n,mmax, dp[501][501], dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int dfs(int i, int j)
{
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	int mm;
	for (int d = 0; d < 4; d++)
	{
		if (i + dy[d] >= 0 && i + dy[d] < n && j + dx[d] >= 0 && j + dx[d] < n && arr[i][j] < arr[i + dy[d]][j + dx[d]])
		{
			if (dp[i + dy[d]][j + dx[d]] == -1)
			{
				dp[i][j] = dfs(i + dy[d], j + dx[d]);
			}
			mm = max(mm, dp[i + dy[d]][j + dx[d]]);
		}
	}
	return dp[i][j] = (mm+1);
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mmax = max(mmax,dfs(i, j));
		}
	}
	cout << mmax;
	return 0;
}