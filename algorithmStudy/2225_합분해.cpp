#include <iostream>
using namespace std;
int dp[201][201],n,k;
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;
	for (int i = 1; i < k; i++)
		dp[i][0] = i + 1;
	for (int i = 1; i < k; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000000;
	cout << dp[k - 1][n-1];
	return 0;
}

