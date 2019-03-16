#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m,a,b, crnt, d[20001], *_m, _count;
vector<int> arr[20001];
queue<int> q;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 2; i <= n; i++)
		d[i] = 987654321;
	q.push(1);
	while (!q.empty())
	{
		crnt = q.front();
		q.pop();
		for (int i = 0; i < arr[crnt].size(); i++)
		{
			if (d[arr[crnt][i]]==987654321)
			{
				q.push(arr[crnt][i]);
				d[arr[crnt][i]] = min(d[arr[crnt][i]], d[crnt] + 1);
			}
		}
	}
	_m = max_element(d+1, d + n+1);
	for (int i = 1; i <= n; i++)
		if (d[i] == *_m) _count++;
	cout << _m - d<<" "<<*_m << " " << _count;
	return 0;
}