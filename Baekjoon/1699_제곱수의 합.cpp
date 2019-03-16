#include<iostream>
using namespace std;
int n,arr[100001];
int main(void)
{
	cin >> n;
	for (int i = 1; i*i <= n; i++)
		arr[i*i] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i]) continue;
		arr[i] = 100000;
		for (int j = 1; j*j <= i; j++)
			if (arr[i] > arr[i - j * j] + 1) arr[i] = arr[i - j * j] + 1;
	}
	cout << arr[n];
	return 0;
}