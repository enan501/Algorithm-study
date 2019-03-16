#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
	int a;
	int b;
	int w;
	edge():a(-1),b(-1),w(0) {}
	edge(int _a, int _b, int _w): a(_a),b(_b),w(_w) {}
	bool operator <(edge& E)
	{
		return w < E.w;
	}
};

priority_queue<edge> arr;
priority_queue<edge> next;

bool visited[10000];
int main(void)
{
	int v = 0, e = 0, count = 0;
	int n[3] = { 0,0,0 };
	//fill(parent, parent + 10000, -1);
	scanf_s("%d %d", &v, &e);
	for (int i = 0; i < e; i++)
	{
		for(int j = 0;j<3;j++)
			scanf_s("%d", &n[j]);
		arr.push(edge(n[0]-1, n[1]-1, n[2]));
	}
	visited[arr.top().a] = true;
	
	while (count != v)
	{
		
	}
	return 0;
}
