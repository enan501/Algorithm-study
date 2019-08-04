#include<iostream>
#include<algorithm>
using namespace std;
int n, k, coin[101], dp[10001];
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	dp[0] = 1;
	sort(coin, coin + n);
	for (int j = 0 ; j < n;j++)
		for (int i = 1; i <= k; i++)
			if (i - coin[j] >= 0) dp[i] += dp[i - coin[j]];
	cout << dp[k];
	return 0;
}