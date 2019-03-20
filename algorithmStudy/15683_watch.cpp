#include <stdio.h>
#include <vector>
using namespace std;
int** arr = NULL;
int n = 0, m = 0, least = 987654321;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> v;
void watch(int x, int y, int dir, int deWatch) //한쪽 방향으로 감시하는 함수
{
	while (y >= 0 && x >= 0 && y < n && x < m && arr[y][x] != 6)
	{
		if (arr[y][x] <= 0)
			arr[y][x] -= deWatch; //감시할때는 1씩 감소, 감시 끝나고 방향 돌릴 때 다시 1씩 증가
		x += dx[dir];
		y += dy[dir];
	}
}
int cal() //최소 사각지대 계산하는 함수
{
	int ret = 0;
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[k][j] == 0)
				ret++;
		}
	}
	if (least > ret)
		least = ret;
	return ret;
}
void func(int index) //dfs 재귀
{
	int ret = 0, val = 0;
	int i = v[index];
	val = arr[i / m][i%m];

	for (int t = 0; t < 4; t++) //4방향 다 감시해봄
	{
		watch(i%m + dx[t], i / m + dy[t], t, 1); //1번 카메라일때는 그냥 한뱡향 감시
		if (val == 2) //2번이면 1번째거의 반대쪽도
			watch(i%m + dx[(t + 2) % 4], i / m + dy[(t + 2) % 4], (t + 2) % 4, 1);
		if (val > 2) //3~5번은 한방향씩 더 감시하면 됌
		{
			for (int cam = 1; cam < val - 1; cam++)
				watch(i%m + dx[(t + cam) % 4], i / m + dy[(t + cam) % 4], (t + cam) % 4, 1);
		}
		if (index < v.size() - 1) //카메라 탐색 덜 했으면
			func(index + 1);
		else //모든 카메라 탐색 다 했으면
		{
			cal();
		}
		watch(i%m + dx[t], i / m + dy[t], t, -1); //방향을 돌려야 하므로 전에 감시했던 거 지워주는 부분
		if (val == 2)
			watch(i%m + dx[(t + 2) % 4], i / m + dy[(t + 2) % 4], (t + 2) % 4, -1);
		if (val > 2)
		{
			for (int cam = 1; cam < val - 1; cam++)
				watch(i%m + dx[(t + cam) % 4], i / m + dy[(t + cam) % 4], (t + cam) % 4, -1);
		}
	}
}



int main(void)
{
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] > 0 && arr[i][j] < 6)
				v.push_back(i*m + j); //카메라 있는 칸의 인덱스를 벡터에 넣어줌
		}
	}
	least = cal();
	if (v.size() > 0) func(0);
	printf("%d", least);
	scanf_s("%d", &n);
	return 0;
}