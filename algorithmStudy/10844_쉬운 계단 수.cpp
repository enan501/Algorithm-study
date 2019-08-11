#include<iostream>
using namespace std;
int ans, n, dp[10][101];
int func(int num, int i) {
	if (i == n-1) return 1;
	if (dp[num][i]) return dp[num][i];
	else {
		if(num != 0) dp[num][i] += func(num-1, i+1) % 1000000000;
		if(num != 9) dp[num][i] += func(num+1, i+1) % 1000000000;
		return dp[num][i] % 1000000000;
	}
}
int main(void) {
	cin >> n;
	for (int num = 1; num < 10; num++) {
		ans += func(num, 0) % 1000000000;
		ans %= 1000000000;
	}
	cout << ans;
	return 0;
}