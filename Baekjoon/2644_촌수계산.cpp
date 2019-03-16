#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int depth[101];
vector<int> child[101];
int n, m, a, b, x, y, answer;
void caldepth(int i)
{
	depth[i] = depth[arr[i][1]]+1;
	for (int j = 0; j < child[i].size(); j++)
		caldepth(child[i][j]);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[y][1] = x;
		
		child[x].push_back(y);
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (arr[i][1] == 0)
			caldepth(i);
	}
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < n+1; j++)
			if (arr[i][j] != 0) arr[i][j + 1] = arr[arr[i][j]][1]; else break;
	if (depth[a] > depth[b])
		a = arr[a][answer = depth[a] - depth[b]];
	else if (depth[b] > depth[a])
		b = arr[b][answer = depth[b] - depth[a]];
	if (a != b)
	{
		for (int i = 1; i < n + 1; i++)	
		{
			if (arr[a][i] == 0 || arr[b][i] == 0)
			{
				answer = -1;
				break;
			}
			else if (arr[a][i] == arr[b][i])
			{
				answer += i * 2;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}