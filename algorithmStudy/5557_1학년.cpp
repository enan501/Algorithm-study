#include<iostream>
using namespace std;
int n, arr[101];
long long int dp[101][22];
long long int func(int i, int sum) {
	if (i == n - 1)
		return dp[i][sum] = (sum == arr[n - 1]);
	if (dp[i][sum] == -1) dp[i][sum] = 0;
	if (sum + arr[i] <= 20) {
		if (dp[i + 1][sum + arr[i]] != -1) dp[i][sum] += dp[i + 1][sum + arr[i]];
		else dp[i][sum] += func(i + 1, sum + arr[i]);
	}
	if (sum - arr[i] >= 0) {
		if (dp[i + 1][sum - arr[i]] != -1) dp[i][sum] += dp[i + 1][sum - arr[i]];
		else dp[i][sum] += func(i + 1, sum - arr[i]);
	}
	return dp[i][sum];
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 22; j++)
			dp[i][j] = -1;
	cout << func(1, arr[0]);
	return 0;
}
