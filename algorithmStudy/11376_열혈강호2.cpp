#include<iostream>
#include<string.h>
using namespace std;
int n, m,k,t,cnt,arr[1001][1001],work[1001];
bool visit[2][1001];
int dfs(int manNum)
{
	if (visit[1][manNum]) return false;
	if (visit[0][manNum]) visit[1][manNum] = true;
	else visit[0][manNum] = true;
	for (int i = 1; i <= m; i++)
	{
		if (arr[manNum][i] && (!work[i] || dfs(work[i])))
		{
			work[i] = manNum;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		while (t--)
		{
			cin >> k;
			arr[i][k] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visit[0], 0, sizeof(visit[0]));
		memset(visit[1], 0, sizeof(visit[1]));
		if (dfs(i)) cnt++;
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}