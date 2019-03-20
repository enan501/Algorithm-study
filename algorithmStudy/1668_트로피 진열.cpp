#include<iostream>
using namespace std;
int arr[51], n, cnt, m;
int main(void)
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
	for (int i = 0; i<n; i++)
	{
		if (arr[i]>m)
		{
			m = arr[i];
			cnt++;
		}
	}
	cout << cnt << ' ';
	m = 0;
	cnt = 0;
	while (n--)
	{
		if (arr[n]>m)
		{
			m = arr[n];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}