#include<iostream>
using namespace std;
int n, k, chu[31],m,flag;
bool dp[31][30002];
void func(int i,int s) {
	if (dp[i][s + 15000] || i > n) {
		return;
	}
	func(i + 1, s + chu[i]);
	func(i + 1, s - chu[i]);
	func(i + 1, s);
	dp[i][s + 15000] = true;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> chu[i];
	func(0, 0);
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> m;
		if (m > 15000) cout << "N ";
		else {
			for (int j = 0; j <= n; j++) {
				if (dp[j][m + 15000]) {
					flag = true;
					break;
				}
			}
			if (flag) cout << "Y ";
			else cout << "N ";
			flag = false;
		}
	}
	return 0;
}