#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int n, arr[21][21], fSize = 2, cnt, ans, sy, sx, cy, cx, dx[4] = { 0,-1,1,0 }, dy[4] = { -1,0,0,1 }, dist[21][21],d=999999;
vector<pair<int, int>> v; //������ �ִ� ������ ��ǥ ����
queue<pair<int, int>> q; //bfs��
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
	do { //����� 1���� �Ա� = 1����
		v.clear();
		sy = q.front().first;
		sx = q.front().second;
		dist[sy][sx] = 1;
		while (!q.empty()) { //bfs
			cy = q.front().first;
			cx = q.front().second;
			q.pop();
			if (dist[cy][cx] == d) break; // bfs�Ҷ� �̹� ť�� ����ִ� ������ġ�� Ž�� ������
			for (int i = 0; i < 4; i++) {
				if (cy + dy[i] < n && cy + dy[i] >= 0 && cx + dx[i] < n && cx + dx[i] >= 0 && !dist[cy + dy[i]][cx + dx[i]] && arr[cy + dy[i]][cx + dx[i]] <= fSize) {
					dist[cy + dy[i]][cx + dx[i]] = dist[cy][cx] + 1; //�Ÿ� ����
					if (arr[cy + dy[i]][cx + dx[i]] && arr[cy + dy[i]][cx + dx[i]] < fSize) { //������������
						v.push_back(make_pair(cy + dy[i], cx + dx[i]));
						d = dist[cy + dy[i]][cx + dx[i]]; //����Ÿ� �����ϰ� �� �Ÿ����� ���ָ� �Ȱ�����
					}
					else if (v.empty()) //��������� ������ ť�� ������ġ ������ �ʿ� X
						q.push(make_pair(cy + dy[i], cx + dx[i]));
				}
			}
		}
		if (!v.empty()) { //���� �� �ִ� ����� ����
			iter = min_element(v.begin(), v.end()); //������
			arr[iter->first][iter->second] = 9;
			arr[sy][sx] = 0;
			cnt++;
			if (cnt == fSize) { //����� ������
				fSize++;
				cnt = 0;
			}
			ans += d - 1; //�ð� �߰�(�Ÿ� ó���� 1�ν����ؼ� 1�������)
			for (int i = 0; i < n; i++) memset(dist[i], 0, sizeof(dist[i]));
			while (!q.empty()) q.pop();
			q.push(*iter);
			d = 999999;
		}
	} while (!v.empty());

	cout << ans;
	return 0;
}
