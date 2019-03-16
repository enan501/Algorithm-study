#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[1000001];
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			if (i % 3 == 0)
				dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) + 1;
			else
				dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else
		{
			if (i % 3 == 0)
				dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
			else
				dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[n];
}