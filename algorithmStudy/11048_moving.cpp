#include <stdio.h>
#include <algorithm>
using namespace std;
int **arr = NULL;
int **dp = NULL;
int dfs(int x, int y)
{
	if (y < 0 || x < 0)
		return -987654321;
	if (dp[y][x] != -1)
		return dp[y][x];
	else
		return dp[y][x] = arr[y][x] + max(dfs(x - 1, y),dfs(x, y - 1));
}
int main(void)
{
	int n = 0, m = 0;
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	dp = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];
		dp[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			scanf_s("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dp[0][0] = arr[0][0];
	printf("%d", dfs(m-1,n-1));
	scanf_s("%d", &n);
	return 0;
}