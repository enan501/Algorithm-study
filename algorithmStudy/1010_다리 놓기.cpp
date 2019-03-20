#include<iostream>
using namespace std;
int t, n, m;
long long ans;
int main(void)
{
	cin >> t;
	while (t--)
	{
		ans = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			(ans *= m--)/=i;
		cout << ans<<'\n';
	}
	return 0;
}