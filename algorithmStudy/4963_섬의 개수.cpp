#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int w, h, cnt, y, x;
bool arr[52][52];
queue<pair<int,int>> q;
int main(void) {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++)
			memset(arr[i], 0, sizeof(arr[i]));
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> arr[i][j];
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++){
				if (arr[i][j]) {
					q.push(make_pair(i, j));
					cnt++;
				}
				while (!q.empty()) {
					y = q.front().first;
					x = q.front().second;
					q.pop();
					for (int dy = -1; dy <= 1; dy++) {
						for (int dx = -1; dx <= 1; dx++) {
							if (arr[y + dy][x + dx]) {
								q.push(make_pair(y + dy, x + dx));
								arr[y + dy][x + dx] = 0;
							}
						}
					}
				}
			}
		}
		cout << cnt<<'\n';
		cnt = 0;
	}
	return 0;
}