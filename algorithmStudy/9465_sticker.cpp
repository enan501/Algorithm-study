#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][100000];
int dp[2][100000];
int main(void)
{
	ios_base::sync_with_stdio(false);
	int t = 0, n = 0;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
	return 0;
}