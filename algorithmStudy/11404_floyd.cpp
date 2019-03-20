#include <stdio.h>
using namespace std;

int main(void)
{
	int n = 0, m = 0, start = 0, dst = 0, cost=0;
	int ** arr = NULL;
	scanf_s("%d", &n);
	arr = new int*[n];
	for (int i = 0; i < n; i++) 
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 100001; //문제 조건에서 주어지는 값은 100000 이하이므로 INF값으로 초기화
		}
	}
	
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) 
	{
		scanf_s("%d %d %d", &start, &dst, &cost);
		if (arr[start-1][dst-1] > cost) //지역이 겹치는 버스가 있을 때 최소값만 저장
			arr[start-1][dst-1] = cost;
	}
	for (int t = 0; t < n; t++) //플로이드-와샬 알고리즘. *거쳐가는 지역이 제일 처음에 와야함
	{
		for (int i = 0; i < n; i++) 
		{
				for (int j = 0; j < n; j++)
				{
					if (i!=j && arr[i][t] + arr[t][j] < arr[i][j])
						arr[i][j] = arr[i][t] + arr[t][j];
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]>100000) //문제조건에서 연결되지 않은 곳은 0으로 출력해야 한다고 함
				arr[i][j] = 0;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	scanf_s("%d", &n);
	return 0;
}