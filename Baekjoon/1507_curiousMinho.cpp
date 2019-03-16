#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int n = 0, sum = 0;
	int** arr = NULL;
	bool** deleted = NULL;
	scanf_s("%d", &n);
	arr = new int*[n];
	deleted = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		memset(arr[i], 0, sizeof(int)*n);
		deleted[i] = new bool[n];
		memset(deleted[i], false, sizeof(bool)*n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k == i || k == j || i == j)
					continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) //주어진 값이 최소 이동시간이 아닌 경우 -1출력
				{
					printf("-1");
					return 0;
				}
				if (arr[i][j] == arr[i][k] + arr[k][j]) //i->j는 k를 경유해서 가는 시간이므로 빼도 됨
				{
					deleted[i][j] = true;
				}

			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i][j] > 0 && deleted[i][j] == false) //delete배열에 포함되지 않고 값이 남아 있으면 꼭 필요한 간선
			{
				sum += arr[i][j];
			}
		}
	}
	printf("%d", sum);
	return 0;
}