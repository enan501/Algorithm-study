#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int n = 0, m = 0, a=0,b=0, least = 0;
	int** arr = NULL;
	int* list = NULL;
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	list = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		memset(arr[i], 0, sizeof(int)*n);
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &a, &b);
		arr[a-1][b-1] = 1;
		arr[b-1][a-1] = 1;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k == i || k == j || i == j)
					continue;
				if (arr[i][k] * arr[k][j] != 0) //배열 초기화를 0대신 INF값으로 해주면 플로이드 알고리즘 그대로 써도 됨
				{
					if (arr[i][j] == 0 || arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{ 
			list[i] += arr[i][j];
		}
		if (list[least] > list[i])
			least = i;
	}
	printf("%d", least+1);
	scanf_s("%d", &n);
	return 0;
}