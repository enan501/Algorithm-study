#include<iostream>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
int n, l, r, arr[102][102],visit[51][51], y, x, sum, cnt, ans, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool flag;
queue<pair<int,int>> q,qq;
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i*2][j*2]; 
	for(;;ans++) {
		for (int i = 0; i < n; i++)
			memset(visit[i], 0, sizeof(visit[i]));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0 && abs(arr[i * 2][j * 2] - arr[(i - 1) * 2][j * 2]) >= l && abs(arr[i * 2][j * 2] - arr[(i - 1) * 2][j * 2]) <= r)
					arr[i * 2 - 1][j * 2] = 1;
				if (j > 0 && abs(arr[i * 2][j * 2] - arr[i * 2][(j - 1) * 2]) >= l && abs(arr[i * 2][j * 2] - arr[i * 2][(j - 1) * 2]) <= r)
					arr[i * 2][j * 2 - 1] = 1;
			}
		}
		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum = cnt = 0;
				q.push(make_pair(i * 2, j * 2));
				qq.push(make_pair(i * 2, j * 2));
				while (!q.empty()) {
					y = q.front().first;
					x = q.front().second;
					visit[y / 2][x / 2] = 1;
					sum += arr[y][x];
					cnt++;
					q.pop();
					for (int d = 0; d < 4; d++) {
						if (y + dy[d] >= 0 && y + dy[d] < n * 2 && x + dx[d] >= 0 && x + dx[d] < n * 2 && !visit[y / 2 + dy[d]][x / 2 + dx[d]] && arr[y + dy[d]][x + dx[d]]) {
							visit[y / 2 + dy[d]][x / 2 + dx[d]] = 1;
							qq.push(make_pair(y + dy[d] * 2, x + dx[d] * 2));
							q.push(make_pair(y + dy[d] * 2, x + dx[d] * 2));
						}
					}
				}
				if (qq.size() > 1) flag = true;
				else qq.pop();
				while (!qq.empty()) {
					y = qq.front().first;
					x = qq.front().second;
					qq.pop();
					arr[y][x] = sum / cnt;
				}
			 }
		}
		if (!flag) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0) arr[i * 2 - 1][j * 2] = 0;
				if (j > 0) arr[i * 2][j * 2 - 1] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}