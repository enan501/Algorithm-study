#include<stdio.h>
using namespace std;
int n, arr[2001], qn, qstart, qend;
bool dp[2001][2001];
int main() {

	scanf("%d", &n);
	scanf("%d", &arr[0]);
	dp[0][0] = 1;

	for (int i = 1; i < n; i++){
		scanf("%d", &arr[i]);
		dp[i][i] = 1;
		dp[i-1][i] = (arr[i] == arr[i - 1]);
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j+i < n; j++) {
			if (dp[j+1][j+i-1] && arr[j] == arr[j+i])
				dp[j][j+i] = 1; 
		}
	}

	scanf("%d", &qn);
	for (int i = 0; i < qn; i++) {
		scanf("%d %d", &qstart , &qend);
		printf("%d\n", dp[qstart - 1][qend - 1]);
	}

	return 0;
}