#include<iostream>
using namespace std;
int n, m, x, y, k,dir,temp, arr[21][21], dice[6], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
int main(void) {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	while (k--) {
		cin >> dir;
		dir--;
		if (y + dy[dir] >= 0 && y + dy[dir] < n && x + dx[dir] >= 0 && x + dx[dir] < m) {
			if (dir == 0) {
				temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
			}
			else if (dir == 1) {
				temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;
			}
			else if (dir == 2) {
				temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;
			}
			else if (dir == 3) {
				temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;
			}
			y += dy[dir];
			x += dx[dir];
			if (arr[y][x]) {
				dice[5] = arr[y][x];
				arr[y][x] = 0;
			}
			else
				arr[y][x] = dice[5];
			cout << dice[0]<<'\n';
		}
	}
	return 0;
}