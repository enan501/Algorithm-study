#include<iostream>
#include<algorithm>
using namespace std;
int arr[100];
int des[100];
int dp[3][100];
int main(void)
{
	ios_base::sync_with_stdio(false);
	int n = 0, sub = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		cin >> des[i];
	for (int i = 3; i < n; i++)
	{
		sub = des[i] - arr[i];
		//if (sub < 0)
		//	sub = min(sub + 10, sub * -1);
		//else if (sub > 0)
		//	sub = min(sub, sub * -1 + 10);
		dp[0][i] = des[i] - arr[i]; //µ¹¸²
		dp[1][i] = des[i] - dp[1][i];
		dp[2][i] = des[i] - dp[2][i];

		dp[1][i + 1] = (dp[0][i+1] + dp[0][i])%10;
		dp[1][i + 2] = dp[0][i];
	}
	return 0;
}