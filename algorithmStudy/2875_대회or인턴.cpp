#include<iostream>
using namespace std;
int n, m, k, ans,a;
int main(void)
{
	cin >> n >> m >> k;
	if (n > m * 2)
	{
		a = k - (n - m * 2);
		if (a < 0) a = 0;
		ans = m - (a + 2) / 3;
	}
	else if (n < m * 2)
	{
		a = k - ((m * 2 - n+1)/2 + n % 2);
		if (a < 0) a = 0;
		ans = n / 2 - (a + 2) / 3;
	}
	else
		ans = m - (k + 2) / 3;
	if (ans < 0) ans = 0;
	cout << ans;
	return 0;
}