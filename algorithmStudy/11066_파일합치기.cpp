#include<iostream>
#include<algorithm>
using namespace std;
int t, n, dp[501][501], sum[501];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int c = 0; c < t; c++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				dp[i][j] = 987654321;
			cin>>sum[i];
			sum[i] += sum[i - 1];
			dp[i][i] = 0;
		}
		for(int i=n;i>0;i--)
			for(int j=i+1;j<=n;j++)
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
		cout << dp[1][n]<<'\n'; 
	}
	return 0;
}