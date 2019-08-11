#include<iostream>
using namespace std;
int n, l, arr[2][101][101], ans;

int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[0][i][j];
			arr[1][j][i] = arr[0][i][j];
		}
	}
	for (int g = 0; g < 2; g++) {
		for (int i = 0; i < n; i++) {
			int j = 0;
			for (; j < n-1; j++) {
				if (arr[g][i][j + 1] == arr[g][i][j] - 1) { //내리막길
					int t = 1;
					for (; t < l; t++)
						if (!(j + 1 + t < n && arr[g][i][j + 1 + t] == arr[g][i][j + 1])) break;
					if (t == l) j += (l-1);
					else break;
				}
				else if (arr[g][i][j + 1] == arr[g][i][j] + 1) { //오르막길
					int t = 1;
					for (; t < l; t++)
						if (!(j - t >= 0 && arr[g][i][j - t] == arr[g][i][j])) break;
					if (t != l) break;

					bool flag = false;
					for (t=l; t < l*2; t++)
						if (j - t >= 0 && arr[g][i][j - t] > arr[g][i][j]) flag = true;
					if (flag) break;

				}
				else if (arr[g][i][j + 1] != arr[g][i][j]) break; //평지
			}
			if (j == n-1) ans++;
		}
	}
	cout << ans;
	return 0;
}