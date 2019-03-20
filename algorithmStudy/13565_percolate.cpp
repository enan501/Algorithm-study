#include <stdio.h>
bool arr[1000][1000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
bool check = false;
void dfs(int x, int y)
{
	if (y == m - 1) check = true;
	if (check) return;
	for (int i = 0; i < 4; i++)
	{
		if (arr[y + dy[i]][x + dx[i]] || x+dx[i] < 0 || x+dx[i] == n || y+dy[i] < 0) continue;
		arr[y][x] = true;
		dfs(x + dx[i], y + dy[i]);
	}
}
int main(void)
{
	char ch = 0;
	scanf_s("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%c", &ch);
			if (ch != '1' && ch != '0')
			{
				j--;
				continue;
			}
			arr[i][j] = (ch == '1');
		}
	}
	for (int i = 0; i < n; i++)
		if(!arr[0][i]) dfs(i,0);
	if (check) printf("YES");
	else printf("NO");
	return 0;
}