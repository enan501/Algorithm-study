#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,cnt,bans,wans, arr[10][10];
bool ld[21], rd[21];
vector<int> bx, by, wx, wy;
int bfunc(int i,int cnt) {
	for (int t = i; t < bx.size(); t++) {
		if (!rd[bx[t] + by[t]] && !ld[bx[t] - by[t] + n - 1]) {
			rd[bx[t] + by[t]] = ld[bx[t] - by[t] + n - 1] = 1;
			bfunc(t + 1,cnt+1);
			rd[bx[t] + by[t]] = ld[bx[t] - by[t] + n - 1] = 0;
		}
	}
	bans = max(bans, cnt);
}
int wfunc(int i, int cnt) {
	for (int t = i; t < wx.size(); t++) {
		if (!rd[wx[t] + wy[t]] && !ld[wx[t] - wy[t] + n - 1]) {
			rd[wx[t] + wy[t]] = ld[wx[t] - wy[t] + n - 1] = 1;
			wfunc(t + 1, cnt + 1);
			rd[wx[t] + wy[t]] = ld[wx[t] - wy[t] + n - 1] = 0;
		}
	}
	wans = max(wans, cnt);
}
int main(void){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				if ((i - j) % 2) {
					bx.push_back(j);
					by.push_back(i);
				}
				else {
					wx.push_back(j);
					wy.push_back(i);
				}
			}
		}
	}
	for (int t = 0; t < bx.size(); t++)
		bfunc(t, 0);
	for (int t = 0; t < wx.size(); t++)
		wfunc(t, 0);
	cout << bans+wans;
	return 0;
}