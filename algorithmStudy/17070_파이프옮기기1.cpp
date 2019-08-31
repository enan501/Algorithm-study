#include<iostream>
using namespace std;
int n, dp[3][17][17];
bool arr[17][17];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int j = 1; j < n; j++) { //첫번째줄
		if (arr[0][j]) break;
		else dp[0][0][j] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			//dp[shape][i][j] = 현재칸에 shape모양으로 오는 경우의수(shape 0=가로, 1=세로, 2대각선)
			if (!arr[i][j]) {
				//왼쪽에서 오는 경우는 가로, 대각선인 경우. 무조건 가로
				dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
				//위에서 오는 경우는 세로, 대각선인 경우. 무조건 세로
				dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
				//왼쪽위에서 오는 경우는 shape 상관 없음. 무조건 대각선
				if(!arr[i-1][j] && !arr[i][j-1])
					dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			}
		}
	}
	cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1];
	return 0;
}