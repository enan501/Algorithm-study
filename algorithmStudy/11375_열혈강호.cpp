#include<iostream>
#include<string.h>
using namespace std;
int n, m,t,k,cnt, man[1001], work[1000];
bool arr[1001][1001], visit[1001];
int dfs(int manNum)
{
	if (visit[manNum]) return false;
	visit[manNum] = 1;
	for (int i = 1; i <= m; i++)
	{
		if (arr[manNum][i] && (!work[i] || dfs(work[i])))
		{
			man[manNum] = i;
			work[i] = manNum;
			return true;
		}
	}
	return false;
}
int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
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
		memset(visit, 0, sizeof(visit));
		if(dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}