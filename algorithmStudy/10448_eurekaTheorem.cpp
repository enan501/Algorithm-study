#include<stdio.h>
#include<vector>
using namespace std;

bool dp[1000];
vector<int> T;
int main(void)
{
	int k = 1, t = 0, n = 0;
	while (k*(k + 1) / 2 <= 1000)
	{
		T.push_back(k * (k + 1) / 2);
		k++;
	}
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		if (!dp[n-1])
		{
			for (int j = 0; j < k-1; j++)
			{
				for (int l = j; l < k-1; l++)
				{
					for (int m = l; m < k-1; m++)
					{
						if (n <T[j] + T[l] + T[m]) break;
						dp[T[j] + T[l] + T[m]-1] = true;
					}
				}
			}
		}
		printf("%d\n", dp[n-1]);
	}
	return 0;
}