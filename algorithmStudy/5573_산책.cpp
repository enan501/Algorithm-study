#include<stdio.h>
int h, w, n, x=1, y=1, dp[1002][1002];
bool arr[1002][1002], parr[1002][1002];
int main(void)
{
	scanf_s("%d %d %d", &h, &w, &n);
	dp[1][0] = dp[0][1] = n-1;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			scanf_s("%d", &arr[i][j]);
			dp[i][j] += (dp[i][j-1] + arr[i][j-1]) / 2;
			dp[i][j] += (dp[i-1][j] + !arr[i-1][j]) / 2;
			dp[i][j] % 2 ? parr[i][j] = !arr[i][j] : parr[i][j] = arr[i][j];
		}
	while (y <= h && x <= w)
		parr[y][x] ? x++ : y++;
	printf("%d %d", y, x);
	return 0;
}


