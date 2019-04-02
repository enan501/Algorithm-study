#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m, mmax,cnt,cx,cy, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, arr[51][51];
char ch;
bool visit[51][51];
queue<pair<int, int>> q;
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch;
			if (ch == 'L') arr[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			if (arr[i][j])
			{
				arr[i][j] = 1;
				for (int k = 0; k < n; k++)
					memset(visit, 0, sizeof(visit));
				cnt = 0;
				q.push(make_pair(i,j));
				visit[i][j] = 1;
				while (!q.empty())
				{
					cy = q.front().first;
					cx = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						if (cy + dy[i] >= 0 && cy + dy[i] < n && cx + dx[i] >= 0 && cx + dx[i] < m && !visit[cy + dy[i]][cx + dx[i]] && arr[cy + dy[i]][cx + dx[i]])
						{
							visit[cy + dy[i]][cx + dx[i]] = 1;//이걸 이안에서 안해주면 메모리초과남
							q.push(make_pair(cy + dy[i], cx + dx[i]));
							cnt = arr[cy + dy[i]][cx + dx[i]] = arr[cy][cx] + 1;
						}
					}
				}
				mmax = max(mmax,cnt);
			}
		}
	}
	cout << mmax-1;
	return 0;
}
