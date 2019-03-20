#include<iostream>
using namespace std;
int n, cnt, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char arr[100][100];
bool visit[100][100];
char crnt;
void dfs(int x, int y)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
		if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < n && !visit[y + dy[i]][x + dx[i]] && arr[y+dy[i]][x+dx[i]] == crnt) dfs(x + dx[i], y + dy[i]);
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visit[i][j])
			{
				cnt++;
				crnt = arr[i][j];
				dfs(j, i);
			}

	cout << cnt<<' ';
	cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = 0;
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visit[i][j])
			{
				cnt++;
				crnt = arr[i][j];
				dfs(j, i);
			}
	cout << cnt;

	return 0;
}