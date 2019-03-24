#include<iostream>
#include<string.h>
using namespace std;
int n, m, s, t,cnt, cow[201], barn[201];
bool arr[201][201], visit[201];
bool dfs(int a)
{
	if (visit[a]) return false;
	visit[a] = true;
	for (int i = 1; i <= m; i++)
	{
		if (arr[a][i] && (!barn[i] || dfs(barn[i])))
		{
			cow[a] = i;
			barn[i] = a;
			return true;
		}
	}
	return false;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		while (s--)
		{
			cin >> t;
			arr[i][t] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}