#include <iostream>
#include <algorithm>
using namespace std;
int n, k, arr[101], dp[10002];
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < 10002; i++)
		dp[i] = 99999;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i]<10002)
			dp[arr[i]] = 1;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if(j-arr[i]>=0)
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[k] == 99999) cout << -1;
	else cout << dp[k];
	return 0;
}

//arr=  1 2 5 6  7  9  10
//sum=  1 3 8 14 21 30 40
//0 
//1 1
//2 1
//3 
//4
//5 1
//6 1
//7 1
//8
//9 1
//10 1
