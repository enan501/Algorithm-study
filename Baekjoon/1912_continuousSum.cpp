#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int main(void)
{
	ios_base::sync_with_stdio(false);
	int n = 0, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n != 1)
	{
		for (int i = n - 2; i >= 0; i--)
			arr[i] = max(arr[i], arr[i] + arr[i + 1]);
	}
	cout << *max_element(arr,arr+n) << endl;
	return 0;
}
