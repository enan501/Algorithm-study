#include<iostream>
using namespace std;
int arr[100001], t, n, c, m, cnt;
int main(void)
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> c;
			cin >> arr[c];
		}
		m = arr[1];
		cnt = 1;
		for (int i = 2; i <= n; i++)
		{
			if (arr[i]<m)
			{
				m = arr[i];
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}