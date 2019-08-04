#include<iostream>
#include<algorithm>
using namespace std;
int r, c, n;
char ch;
int arr[1503][1503], brr[1503][1503], dp[1503][1503];
int main(void){
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ch >> n;
			if (ch == 'A')
				arr[i][j] = n;
			else
				brr[i][j] = n;
		}
	}
	for (int i = 1; i < r; i++) {
		for (int j = 0; j < c; j++) {
			brr[i][j] += brr[i - 1][j];
			arr[r - i -1][j] += arr[r - i][j];
		}
	}
	dp[0][0] = arr[1][0];
	for (int j = 1; j < c; j++)
		dp[0][j] = dp[0][j-1] + arr[1][j];
	for (int i = 1; i < r; i++)
		dp[i][0] = arr[i+1][0];
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			dp[i][j] = max(dp[i - 1][j] - arr[i][j] + arr[i+1][j] , 
				max(dp[i - 1][j - 1], dp[i][j - 1]) + arr[i + 1][j] + brr[i - 1][j] );
		}
	}
	cout << dp[r - 1][c - 1];
	return 0;
}