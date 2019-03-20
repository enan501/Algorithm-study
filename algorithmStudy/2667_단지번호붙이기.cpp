// bfs =========================================================

#include<stdio.h>
#include<queue>
using namespace std;
int n, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 },cy,cx,cnt;
bool arr[25][25];
queue<int> qy, qx;
priority_queue<int,vector<int>,greater<int>> pq;
int main(void)
{
	scanf_s("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &arr[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j])
			{
				cnt = 0;
				qy.push(i);
				qx.push(j);
				arr[i][j] = 0;
				while (!qy.empty())
				{
					cnt++;
					cy = qy.front();
					cx = qx.front();
					qy.pop();
					qx.pop();
					for (int k = 0; k < 4; k++)
						if (cy + dy[k] >= 0 && cy + dy[k] < n && cx + dx[k] >= 0 && cx + dx[k] < n && arr[cy + dy[k]][cx + dx[k]])
						{
							qy.push(cy + dy[k]);
							qx.push(cx + dx[k]);
							arr[cy+dy[k]][cx+dx[k]] = 0;
						}
				}
				pq.push(cnt);
			}
	printf("%d\n", pq.size());
	while (!pq.empty())
	{
		printf("%d\n", pq.top());
		pq.pop();
	}
	return 0;
}

// dfs =========================================================

#include<stdio.h>
#include<queue>
using namespace std;
int n, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 },cnt;
bool arr[25][25];
priority_queue<int,vector<int>,greater<int>> pq;
void dfs(int y,int x)
{
	arr[y][x] = 0;
	cnt++;
	for (int i = 0; i < 4; i++)
		if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < n && arr[y + dy[i]][x + dx[i]])
			dfs(y + dy[i], x + dx[i]);
}
int main(void)
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j])
			{
				dfs(i, j);
				pq.push(cnt);
				cnt = 0;
			}
		}
	}
	printf("%d\n", pq.size());
	while (!pq.empty())
	{
		printf("%d\n", pq.top());
		pq.pop();
	}
	return 0;
}