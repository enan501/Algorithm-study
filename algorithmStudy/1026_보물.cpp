#include<iostream>
#include<algorithm>
using namespace std;
int n, s, a[51], b[51];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n,greater<int>());
	for (int i = 0; i < n; i++)
		s += a[i] * b[i];
	cout << s;
	return 0;
}