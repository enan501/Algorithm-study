#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int n = 0;
	char ch = 0;
	bool** arr = NULL;
	scanf_s("%d", &n);
	arr = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new bool[n];
		memset(arr[i], false, sizeof(bool)*n);
	}
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%c", &ch);
			if (ch == 'Y')
				arr[i][j] = true;
		}
		getchar();
	}
	for (int i = 0; i < n; i++) //양방향 간선은 제외하고 단방향 간선의 사이클이 있는지만 조사하면 됨
	{							//양방향 간선은 선을 하나 없애서 사이클이 만들어지지 않게 할 수 있음
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] && arr[j][i] && i != j)
				arr[i][j] = arr[j][i] = false;
		}
	}
	for (int k = 0; k < n; k++)///플로이드로 모든 노드간의 연결을 갱신
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//보통 플로이드 알고리즘에서 i==j인 경우는 제외하지만 
				//이 문제에서는 원래 노드로 돌아오는 사이클을 찾아야 하기 때문에 제외하지 않음
				if (arr[i][k] && arr[k][j])
					arr[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i][i]) // 해당 노드로 다시 돌아오는 경로가 있으면(사이클)
		{
			printf("NO");
			scanf_s("%d", &n);
			return 0;
		}
	}
	printf("YES");
	scanf_s("%d", &n);
	return 0;
}