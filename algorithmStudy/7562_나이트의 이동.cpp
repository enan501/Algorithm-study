#include<iostream>
#include<queue>
using namespace std;
int t, n, cx, cy, lx, ly, dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = {-1,1,-2,2,-2,2,-1,1}, cnt;
queue<pair<int,int>> q;
int main(void)
{
	cin >> t;
	while (t--)
	{
		int arr[301][301] = {};
		cin >> n >> cx >> cy >> lx >> ly;
		q.push(make_pair(cx, cy));
		arr[cy][cx] = 1;
		while (!q.empty())
		{
			cx = q.front().first;
			cy = q.front().second;
			q.pop();
			if (cy == ly && cx == lx) break;
			for (int i = 0; i < 8; i++)
			{
				if (cx + dx[i] >= 0 && cx + dx[i] < n && cy + dy[i] >= 0 && cy + dy[i] < n && !arr[cy + dy[i]][cx + dx[i]])
				{
					arr[cy + dy[i]][cx + dx[i]] = arr[cy][cx] + 1;
					q.push(make_pair(cx + dx[i], cy + dy[i]));
				}
			}
		}
		while (!q.empty()) q.pop();
		cout<< arr[ly][lx]-1<<'\n';
	}
	return 0;
}