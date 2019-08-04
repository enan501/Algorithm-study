//#include<stdio.h>
//#include<algorithm>
//using namespace std;
//int n, arr[126][126],dp[126][126], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
//int dfs(int y, int x)
//{
//	int mmin = 999999999;
//	if (y == n - 1 && x == n - 1) return arr[n-1][n-1];
//	dp[y][x] = 0;
//	for (int i = 0; i < 4; i++)
//		if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < n && dp[y+dy[i]][x+dx[i]])
//		{
//			if (dp[y + dy[i]][x + dx[i]] == -1)
//				mmin = min(mmin, dfs(y + dy[i], x + dx[i]));
//			else
//				mmin = min(mmin, dp[y + dy[i]][x + dx[i]]);
//		}
//	return dp[y][x] = arr[y][x] + mmin;
//}
//int main(void)
//{
//	for(int t=1;;t++)
//	{
//		scanf("%d", &n);
//		if (!n) break;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				scanf("%d", &arr[i][j]);
//				dp[i][j] = -1;
//			}
//		}
//		dfs(0, 0);
//		printf("Problem %d: %d\n", t, dp[0][0]);
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int i = 0;
	if ((i = 2 / 3))
		printf("aa%d", i);
	else
		printf("bb%d", i);
	return 0;
}