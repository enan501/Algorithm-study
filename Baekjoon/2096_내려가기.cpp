//#include<stdio.h> //dp 풀이
//#include<algorithm>
//using namespace std;
//int n, dp[100001][3], dpm[100001][3];
//int main(void)
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
//		dpm[i][0] = dp[i][0];
//		dpm[i][1] = dp[i][1];
//		dpm[i][2] = dp[i][2];
//	}
//	for (int i = 1; i < n; i++)
//	{
//		dp[i][0] += max(dp[i - 1][0], dp[i - 1][1]);
//		dp[i][1] += max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
//		dp[i][2] += max(dp[i - 1][1], dp[i - 1][2]);
//		dpm[i][0] += min(dpm[i - 1][0], dpm[i - 1][1]);
//		dpm[i][1] += min(dpm[i - 1][0], min(dpm[i - 1][1], dpm[i - 1][2]));
//		dpm[i][2] += min(dpm[i - 1][1], dpm[i - 1][2]);
//	}
//	printf("%d %d", *max_element(dp[n - 1], dp[n - 1] + 3), *min_element(dpm[n - 1], dpm[n - 1] + 3));
//	return 0;
//}

#include<stdio.h> //슬라이딩 윈도우 풀이
#include<algorithm>
#include<string.h>
using namespace std;
int n, s[3], b[3], st[3], bt[3];
int main(void)
{
	scanf_s("%d %d %d %d", &n, &bt[0], &bt[1], &bt[2]);
	b[0] = s[0] = bt[0];
	b[1] = s[1] = bt[1];
	b[2] = s[2] = bt[2];
	for (int i = 1; i < n; i++)
	{
		scanf_s("%d %d %d", &bt[0], &bt[1], &bt[2]);
		st[0] = bt[0] + min(s[0], s[1]);
		st[1] = bt[1] + min(s[0], min(s[1], s[2]));
		st[2] = bt[2] + min(s[1], s[2]);
		bt[0] += max(b[0], b[1]);
		bt[1] += max(b[0], max(b[1], b[2]));
		bt[2] += max(b[1], b[2]);
		memcpy(b, bt, sizeof(int)*3);
		memcpy(s, st, sizeof(int)*3);
	}
	printf("%d %d", *max_element(b, b + 3), *min_element(s, s + 3));
	return 0;
}