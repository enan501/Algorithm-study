#include <stdio.h>
using namespace std;
int main(void)
{
	int n = 0, longest = 0;
	int* arr = NULL;
	int* dp = NULL;
	scanf_s("%d", &n);
	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		if (longest < dp[i])
			longest = dp[i];
	}
	printf("%d", longest);
	scanf_s("%d", &n);
	return 0;
}