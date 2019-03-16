#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1000], n;
vector<int> v;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else
			*lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
	}
	cout << v.size() - 1;
	return 0;
}