#include <stdio.h>

int main(void) {
	int n = 0, h=1;
	int* arr = NULL, *dp = NULL;
	scanf("%d", &n);
	arr = new int[n];
	dp = new int[n];
	for(int i=0;i<n;i++) 
	scanf("%d", &arr[i]);
	for(int i=0;i<n;i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j]<arr[i] && (dp[j]+1)>dp[i])
				dp[i] = dp[j] + 1;
		}
		if (dp[i]>h) h = dp[i];
	}
	printf("%d", n-h);
	return 0;
}