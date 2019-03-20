#include<iostream>
#include<algorithm>
using namespace std;
int n, x[51], y[51], ans[51];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (x[i] < x[j] && y[i] < y[j]) ans[i]++;
	for (int i = 0; i < n; i++)
		cout << ans[i]+1 << " ";
	return 0;
}