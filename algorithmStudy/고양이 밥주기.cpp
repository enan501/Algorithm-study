//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int n, cat[9][2],dist[9][9],ans=999999999;
//bool visit[9];
//int func(int cur, int ssum, int cnt) {
//	if (cnt == n-1) {
//		return ssum + cat[cur][0]+cat[cur][1];
//	}
//	int temp = 999999999;
//	for (int i = 0; i < n; i++) {
//		if (!visit[i]) {
//			visit[i] = true;
//			temp = min(temp,func(i,ssum+dist[cur][i],cnt+1));
//			visit[i] = false;
//		}
//	}
//	return temp;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> cat[i][0] >> cat[i][1];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			dist[i][j] = abs(cat[i][0] - cat[j][0]) + abs(cat[i][1] - cat[j][1]);
//	for (int i = 0; i < n; i++) {
//		visit[i] = true;
//		ans = min(ans,func(i, cat[i][0] + cat[i][1], 0));
//		visit[i] = false;
//	}
//	cout << ans;
//	return 0;
//}

//비트마스크
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, cat[17][2], dist[17][17], dp[17][1 << 17], ans = 999999999;
int func(int cur, int visit) {
	if (visit == (1 << n) - 1)
		return cat[cur][0] + cat[cur][1];
	if (dp[cur][visit]) return dp[cur][visit];
	dp[cur][visit] = 999999999;
	for (int i = 0; i < n; i++)
		if (!(visit & (1 << i)))
			dp[cur][visit] = min(dp[cur][visit], dist[cur][i] + func(i, visit | (1 << i)));
	return dp[cur][visit];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cat[i][0] >> cat[i][1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = abs(cat[i][0] - cat[j][0]) + abs(cat[i][1] - cat[j][1]);
	for (int i = 0; i < n; i++)
		ans = min(ans, cat[i][0] + cat[i][1] + func(i, 1 << i));
	cout << ans;
	return 0;
}
