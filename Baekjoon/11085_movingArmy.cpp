#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<pair<int, int>> pq[1001];
bool visited[1001];
int main(void)
{
	int p = 0, w = 0, c = 0, v = 0, s= 0, d=0, g = 0, _min = 1000, cur = 0;
	scanf_s("%d %d %d %d", &p, &w, &c, &v);
	for (int i = 0; i < w; i++)
	{
		scanf_s("%d %d %d", &s, &d, &g);
		pq[s].push(make_pair(g, d));
		pq[d].push(make_pair(g, s));
	}
	cur = c;
	visited[c] = true;
	while (cur != v)
	{
		_min = min(_min, pq[cur].top().first);
		while (visited[pq[cur].top().second])
			pq[cur].pop();
		cur = pq[cur].top().second;
		visited[cur] = true;
	}
	printf("%d", _min);
	return 0;
}