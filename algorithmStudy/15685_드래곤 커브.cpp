#include <iostream>
#include <vector>
using namespace std;
int n, x, y, d, g, cnt, arr[101][101], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (n--){
		vector<int> v;
		cin >> x >> y >> d >> g;
		v.push_back(d);
		arr[y][x] = 1;
		arr[y += dy[d]][x += dx[d]] = 1; //세대 0일때
		for (int i = 1; i <= g; i++){ //세대 1부터 g까지 반복
			for (int j = v.size() - 1; j >= 0; j--){ //벡터에서 최근거부터 하나씩 꺼냄
				v.push_back(d = (v[j] + 1) % 4); //현재방향에서 시계방향으로 90도 회전한 방향을 벡터에 저장
				arr[y += dy[d]][x += dx[d]] = 1; //방문한 좌표를 기록
			}
		}
	}
	for (int i = 0; i < 100; i++) //사각형 개수 찾기
		for (int j = 0; j < 100; j++)
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) cnt++;
	cout << cnt;
	return 0;
}