#include<iostream>
#include<algorithm>
using namespace std;
int r, c,cnt, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char arr[20][20];
bool visit[26];
int dfs(int x, int y)
{
	visit[arr[y][x] - 'A'] = 1;
	int m = cnt;
	for (int i = 0; i < 4; i++)
	{
		if (y + dy[i] >= 0 && y + dy[i] < r && x + dx[i] >= 0 && x + dx[i] < c && !visit[arr[y + dy[i]][x + dx[i]] - 'A'])
		{
			cnt++;
			m = max(m, dfs(x + dx[i], y + dy[i]));
		}
	}
	visit[arr[y][x] - 'A'] = 0;
	cnt--;
	return m;
}

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	cnt++;
	cout<<dfs(0, 0);
	return 0;
}