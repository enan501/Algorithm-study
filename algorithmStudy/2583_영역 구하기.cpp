#include <iostream>
#include <queue>
using namespace std;
int m, n, k,lx,ly,rx,ry, arr[101][101],sum;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
priority_queue<int, vector<int>, greater<int> > pq;
void dfs(int x, int y)
{
	sum += arr[y][x] = 1;
	for (int i = 0; i < 4; i++)
		if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m || arr[y+dy[i]][x+dx[i]]) continue;
		else dfs(x + dx[i], y + dy[i]);
}
int main(void)
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int x = lx; x < rx; x++)
			for (int y = ly; y < ry; y++)
				arr[y][x] = 1;
	}
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if (!arr[i][j])
			{ 
				sum = 0;
				dfs(j, i);
				pq.push(sum);
			}
		}
	cout << pq.size() << '\n';
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}