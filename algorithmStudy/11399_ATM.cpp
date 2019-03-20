#include<iostream>
#include<algorithm>
using namespace std;
int n, p[1000], s;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		s += p[i] * (n - i);
	cout << s;
	return 0;
}
