#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, virus,minVirus=99999, arr[8][8], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1};
vector<int> zx, zy, vx, vy;
int dfs(int x, int y)
{
	int sum = 0;
	arr[y][x] = 2;
	for (int i = 0; i < 4; i++)
		if (y + dy[i] >= 0 && y + dy[i] < n&&x + dx[i] >= 0 && x + dx[i] < m && !arr[y + dy[i]][x + dx[i]])
			sum += dfs(x + dx[i], y + dy[i]);
	return sum+1;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2) //바이러스 위치 벡터에 저장
			{
				vy.push_back(i);
				vx.push_back(j);
			}
			else if (!arr[i][j]) //빈칸 위치 벡터에 저장
			{
				zy.push_back(i);
				zx.push_back(j);
			}
		}
	for (int i = 0; i < zy.size() - 2; i++) //3중for문으로 벽 하나씩 모든칸에 세워봄
	{
		arr[zy[i]][zx[i]] = 1; 
		for (int j = i + 1; j < zy.size() - 1; j++)
		{
			arr[zy[j]][zx[j]] = 1;
			for (int k = j + 1; k < zy.size(); k++)
			{
				arr[zy[k]][zx[k]] = 1;
				virus = 0;
				for (int t = 0; t < vy.size(); t++)
					virus += dfs(vx[t], vy[t]); //바이러스마다 dfs로 확장해서 총 넓이 구함
				for (int t = 0; t < zy.size(); t++)
					arr[zy[t]][zx[t]] = 0; //다 조사했으면 원래대로 복귀
				arr[zy[i]][zx[i]] = 1; //첫번째, 두번째 for문의 벽은 그대로 벽으로 두기
				arr[zy[j]][zx[j]] = 1;
				minVirus = min(minVirus, virus); //안전구역의 최대값 구하는거니까 바이러스 넓이는 최소
			}
			arr[zy[j]][zx[j]] = 0;
		}
		arr[zy[i]][zx[i]] = 0;
	}
	cout << zy.size() + vy.size() - 3 -minVirus; //안전구역 = 빈칸 - 추가된 벽 3칸 - 바이러스 넓이
	return 0;
}