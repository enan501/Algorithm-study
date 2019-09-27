#include <iostream>
#include <algorithm>
using namespace std;
int n, k, value[101], weight[101], dp[101][100001];
int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { 
		cin >> weight[i] >> value[i];
		for (int j = 0; j <= k; j++)
			if (j >= weight[i]) dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight[i]] + value[i]);
			else dp[i][j] = dp[i - 1][j];
	}
	cout << dp[n][k];
	return 0;
}