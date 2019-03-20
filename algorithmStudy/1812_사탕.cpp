#include<iostream>
using namespace std;
int n, arr[999],sum;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i] * (i % 2 ? -1 : 1);
	}
	cout << (sum /= 2)<<'\n';
	for(int i=0;i<n-1;i++)
		cout << (sum = arr[i] - sum)<<'\n';
	return 0;
}