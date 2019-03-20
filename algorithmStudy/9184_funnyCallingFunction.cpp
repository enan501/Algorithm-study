#include <stdio.h>
using namespace std;
int dp[21][21][21];
int w(int a, int b, int c)
{
	if (a == 0 || b == 0 || c == 0)
		return 1;
	if (dp[a][b][c] == 0)
	{
		if(a < b && b < c)
			return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		else
			return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	else
		return dp[a][b][c];
}
int main(void)
{
	int a = 0, b = 0, c = 0;
	dp[0][0][0] = 1;
	while (true)
	{
		scanf_s("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = ", a, b, c);
		if (a <= 0 || b <= 0 || c <= 0)
			a = b = c = 0;
		if (a > 20 || b > 20 || c < 20)
			a = b = c = 20;
		printf("%d\n",w(a, b, c));
	}
}