#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n, arr[21][21], fSize = 2, cnt, ans, sy, sx, cy, cx, dx[4] = { 0,-1,1,0 }, dy[4] = { -1,0,0,1 }, dist[21][21],d=999999;
vector<pair<int, int>> v; //먹을수 있는 물고기들 좌표 저장
queue<pair<int, int>> q; //bfs용
vector<pair<int, int>>::iterator iter;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9)
				q.push(make_pair(i, j));
		}
	}
	do { //물고기 1마리 먹기 = 1라운드
		v.clear();
		sy = q.front().first;
		sx = q.front().second;
		dist[sy][sx] = 1;
		while (!q.empty()) { //bfs
			cy = q.front().first;
			cx = q.front().second;
			q.pop();
			if (dist[cy][cx] == d) break; // bfs할때 이미 큐에 들어있는 다음위치들 탐색 방지용
			for (int i = 0; i < 4; i++) {
				if (cy + dy[i] < n && cy + dy[i] >= 0 && cx + dx[i] < n && cx + dx[i] >= 0 && !dist[cy + dy[i]][cx + dx[i]] && arr[cy + dy[i]][cx + dx[i]] <= fSize) {
					dist[cy + dy[i]][cx + dx[i]] = dist[cy][cx] + 1; //거리 갱신
					if (arr[cy + dy[i]][cx + dx[i]] && arr[cy + dy[i]][cx + dx[i]] < fSize) { //먹을수있으면
						v.push_back(make_pair(cy + dy[i], cx + dx[i]));
						d = dist[cy + dy[i]][cx + dx[i]]; //현재거리 저장하고 이 거리보다 더멀리 안갈거임
					}
					else if (v.empty()) //먹을물고기 있으면 큐에 다음위치 저장할 필요 X
						q.push(make_pair(cy + dy[i], cx + dx[i]));
				}
			}
		}
		if (!v.empty()) { //먹을 수 있는 물고기 존재
			iter = min_element(v.begin(), v.end()); //위왼쪽
			arr[iter->first][iter->second] = 9;
			arr[sy][sx] = 0;
			cnt++;
			if (cnt == fSize) { //물고기 레벨업
				fSize++;
				cnt = 0;
			}
			ans += d - 1; //시간 추가(거리 처음에 1로시작해서 1빼줘야함)
			for (int i = 0; i < n; i++) memset(dist[i], 0, sizeof(dist[i]));
			while (!q.empty()) q.pop();
			q.push(*iter);
			d = 999999;
		}
	} while (!v.empty());

	cout << ans;
	return 0;
}
