#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, arr[51][51],x,y,score[51],_min;
vector<int> v;
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(i!=j) arr[i][j] = 987654321;
	while (1)
	{
		cin >> x >> y;
		if (x == -1) break;
		arr[x][y] = arr[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) //플로이드
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 1; i <= n; i++) //점수 = 제일 먼 친구와의 거리
		score[i] = *max_element(arr[i] + 1, arr[i] + n + 1);
	_min = *min_element(score + 1, score + n + 1); //그중 최소값
	for (int i = 1; i <= n; i++)
		if (score[i] == _min) v.push_back(i); //최소값이면 벡터에 번호를 저장
	cout << _min << " " << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}