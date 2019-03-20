#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue> 
#define INF 10000;
using namespace std;

int main(void)
{
	int n = 0, m = 0, sx = 0, sy = 0, dx = 0, dy = 0, S = 0, D = 0, next=0, totalFlow = 0;
	int fx[4] = { 0,0,1,-1 };
	int fy[4] = { 1,-1,0,0 };
	char** arr = NULL;
	int** flow = NULL, **capacity = NULL;
	bool* visit = NULL;
	scanf_s("%d %d", &n, &m);
	arr = new char*[n];
	visit = new bool[n*m];
	memset(visit, false, sizeof(bool)*n*m);
	flow = new int*[n*m];
	capacity = new int*[n*m];
	for (int i = 0; i < n*m; i++)
	{
		flow[i] = new int[n*m];
		memset(flow[i], 0, sizeof(int)*n*m);
		capacity[i] = new int[n*m];
		memset(capacity[i], 0, sizeof(int)*n*m);
		
	}
	//맵 입력
	getchar();
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m];
		memset(arr[i], 0, sizeof(arr[i]));
		for (int j = 0; j < m; j++) {
			scanf_s("%c", &arr[i][j]);
			if (arr[i][j] == 'K')
			{
				sx = j;
				sy = i;
				S = i * m + j;
			}
			else if(arr[i][j] == 'H')
			{
				dx = j;
				dy = i;
				D = i * m + j;
			}
			//else if (ch[i][j] == '#')
			//{ 
 		//		for (int t = 0; t < 4; t++) //벽이면 상하좌우(해당 노드와 통하는 간선) 값 -1
			//	{
			//		if (i + dy < n * 2 - 1 && i + dy > 0 && j + dx < m * 2 - 1 && j + dx > 0)
			//			ch[i + dy][j + dx] == -1;
			//	}
			//}

		}
		getchar();
	}
	if (abs(sx - dx) + abs(sy - dy) == 1)
	{
		printf("-1");
		return 0;
	}
	// 간선 추가
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (j + 1<m && arr[i][j] != '#' && arr[i][j+1] != '#')
			{
				capacity[i*m + j][i*m + j + 1] = INF;
				capacity[i*m + j + 1][i*m + j] = INF;
			}
			if (i + 1<n && arr[i][j] != '#' && arr[i+1][j] != '#' )
			{
				capacity[i*m + j][(i+1)*m + j] = INF;
				capacity[(i+1)*m + j][i*m + j] = INF;
			}
		}
	}
	//최대유량 알고리즘
	while (1)
	{
		int* prev = NULL;
		prev = new int[n*m];
		memset(prev, -1, sizeof(int)*n*m);
		queue<int> q;
		q.push(S);
		//memset(visit, false, sizeof(bool)*n*m);
		visit[S] = true;
		visit[D] = false;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				next = cur + fy[i]*m + fx[i];
				if (next<0 || next>n*m || (i == 2 && next % m == 0) || (i == 3 && cur%m == 0)) 
					continue;
				if (capacity[cur][next] > flow[cur][next] && visit[next]==false)
				{
					q.push(next);
					prev[next] = cur;
					if (next == D)
						break;
				}

			}
			if (next == D)
				break;
		}
		if (prev[D] == -1)
			break;
		for (int i = D; i != S; i = prev[i])
		{
			flow[prev[i]][i] += INF;
			flow[i][prev[i]] -= INF;
			visit[i] = true;
		}
		totalFlow++;
	}
	printf("%d", totalFlow); 
	scanf_s("%d", &n);
	return 0;
}