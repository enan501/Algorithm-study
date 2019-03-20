#include<stdio.h>
#include<string.h>
using namespace std;

int** arr = NULL, **melt = NULL;
bool **visit = NULL;
int n = 0, m = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void func(int i,int j)
{
	visit[i][j] = true;
	for (int t = 0; t < 4; t++)
	{
		if (i + dy[t] < 0 || j + dx[t] < 0 || i + dy[t] == n || j + dx[t] == m)//범위밖
			continue;
		if (visit[i + dy[t]][j + dx[t]] == false) //방문안한 노드이면
		{
			if (arr[i + dy[t]][j + dx[t]] != 0) //다음 노드가 0이 아니면
				func(i + dy[t], j + dx[t]); //재귀 실행
			else
				melt[i][j]--; //다음 노드가 0이면 현재 노드값을 1감소(나중에 한번에 감소시켜야함)
		}
	}
}

int main(void)
{
	int count = 0;
	bool check = false;
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	melt = new int*[n];
	visit = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		memset(arr[i], 0, sizeof(int)*m);
		melt[i] = new int[m];
		memset(melt[i], 0, sizeof(int)*m);
		visit[i] = new bool[m];

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	while (1)
	{
		check = false;
		for (int i = 0; i < n; i++)
		{
			memset(visit[i], 0, sizeof(bool)*m);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] != 0 && check ==false) //0이 아닌 노드를 찾았으면서 해당 년도에 아직 검사 안했으면
				{
					func(i, j); //재귀 실행
					check = true;
					count++; 
				}
				if (arr[i][j] !=0 && visit[i][j] == false && check == true) //방문 안한 0이 아닌 노드를 찾았는데 이미 해당 년도에 검사했으면
				{
					printf("%d", count-1); //count에서 1을 빼는 이유는 두개로 갈라진 년도에도 검사를 하기 때문
					scanf_s("%d", &n);
					return 0;
				}
			}
		}
		for (int i = 0; i < n; i++) //주변의 0 노드 개수만큼 녹는 부분
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] += melt[i][j];
				melt[i][j] = 0;
				if (arr[i][j] < 0)
					arr[i][j] = 0;
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
		if (check == false) //모든 노드를 조사했는데 다 0이면, 즉 둘로 나눠지는 년도 없이 한번에 다 녹으면 반복문 탈출
			break;
		
	}
	printf("0");
	scanf_s("%d", &n);
	return 0;
}