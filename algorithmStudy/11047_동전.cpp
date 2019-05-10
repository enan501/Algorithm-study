#include<iostream>
using namespace std;
int n, k, arr[10],mmax,cnt;
int main(void)
{
	cin >> n>> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] < k)
			mmax = i;
	}
	for (int i = mmax; i >= 0; i--)
	{
		cnt += k / arr[i];
		k %= arr[i];
		if (!k) break;
	}
	cout << cnt;
	return 0;
}