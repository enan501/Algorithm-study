#include<stdio.h>
#include<algorithm>
using namespace std;
int m, n,ans, arr[100001],dp[100001];
int main(void) {
	while(true) {
		scanf("%d %d", &m, &n);
		if (m == 0) break;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[n * i + j]); // == arr[i][j]
			arr[n * i + 1] = max(arr[n * i], arr[n * i + 1]); //arr[i][1] = max(arr[i][0], arr[i][1])
			for (int j = 2; j < n; j++)
				arr[n * i + j] = max(arr[n * i + j - 2] + arr[n * i + j], arr[n * i + j - 1]);
				//arr[i][j] = max(arr[i][j-2] + arr[i][j], arr[i][j-1]
			dp[i] = arr[n * (i + 1) - 1];
		}
		dp[1] = max(dp[0], dp[1]);
		for (int i = 2; i < m; i++)
			dp[i] = max(dp[i - 2] + dp[i], dp[i - 1]);
		printf("%d\n", dp[m - 1]);
	}
	return 0;
}