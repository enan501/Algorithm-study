//´ÙÀÌ³ª¹Í ÇÁ·Î±×·¡¹Ö Ç®ÀÌ
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, valuesum, weightsum, value[102], weight[102], dp[102][100002];
int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
		valuesum += value[i];
		weightsum += weight[i];
	}
	if (weightsum < k) cout << "ÁË¼ÛÇÕ´Ï´Ù ÇÑ½Â¿± º´Àå´Ô";
	else {
		k = weightsum - k;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= k; j++)
				if (j >= weight[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
				else dp[i][j] = dp[i - 1][j];
		cout << valuesum - dp[n][k];
	}
	return 0;
}

////¿ÏÀüÅ½»ö Ç®ÀÌ
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, k, valuesum, weightsum, value[101], weight[101];
//
//int func(int ws, int vs, int i) {
//	if (i > n) return vs;
//	int temp = func(ws, vs, i + 1);
//	if(ws+weight[i]<k)
//		temp = max(temp,func(ws + weight[i], vs + value[i], i + 1));
//	return temp;
//}
//int main(void) {
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> weight[i] >> value[i];
//		valuesum += value[i];
//		weightsum += weight[i];
//	}
//	if (weightsum < k) cout << "ÁË¼ÛÇÕ´Ï´Ù ÇÑ½Â¿± º´Àå´Ô";
//	else {
//		k = weightsum - k;
//		cout << valuesum - func(0, 0, 1);
//	}
//	return 0;
//}