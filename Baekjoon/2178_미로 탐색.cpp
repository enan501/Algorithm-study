#include<stdio.h>
#include<queue>
using namespace std;
int n, m, cx,cy, i, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 }, arr[100][100];
queue<int> qx, qy;
int main(void)
{
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &arr[i][j]); //한글자씩 입력받기
	qx.push(0);
	qy.push(0);
	while (1)
	{
		cx = qx.front(); //cx,cy = 현재좌표
		cy = qy.front();
		qx.pop();
		qy.pop();
		if (cy == (n - 1) && cx == (m - 1)) break;
		for (i = 0; i < 4; i++)
		{
			if (cy + dy[i] >= 0 && cy + dy[i]< n && cx + dx[i] >=0 && cx + dx[i]<m && arr[cy + dy[i]][cx + dx[i]]==1)
			{
				qy.push(cy + dy[i]); //큐에 다음좌표 push
				qx.push(cx + dx[i]);
				arr[cy + dy[i]][cx + dx[i]] = arr[cy][cx] + 1;//배열에 시작점부터 거리 저장
			}
		}
		arr[cy][cx] = 0; //방문한 곳 체크
		
	}
	printf("%d",arr[cy][cx]);
	return 0;
}
