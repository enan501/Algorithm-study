#include<iostream>
using namespace std;
int n, m, r, c, d, cnt, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int arr[51][51], visit[51][51];
void clean(int y, int x, int dir) {
	if (!visit[y][x]) {
		visit[y][x] = true;
		cnt++;
	}
	int i = 0;	
	for (; i < 4; i++) {
		if (!visit[y + dy[(i + 4 - dir) % 4]][x + dx[(i + 4 - dir) % 4]]) {
			clean(y + dy[(i + 4 - dir) % 4], x + dx[(i + 4 - dir) % 4], (3+dir-i) % 4);
			break;
		}
	}
	if (i==4 && !arr[y + dy[(5 - dir) % 4]][x + dx[(5 - dir) % 4]])
		clean(y + dy[(5 - dir) % 4], x + dx[(5 - dir) % 4], dir);
}
int main(void) {
	cin >> n >> m>>r>>c>>d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			visit[i][j] = arr[i][j];
		}
	}
	clean(r, c, d);
	cout << cnt;
	return 0;
}