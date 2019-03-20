#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n = 0, longest = 0, temp = 0;
	int* arr = NULL;
	int* dp = NULL;
	vector<int> v;
	vector<int> st;
	scanf_s("%d", &n);
	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	v.push_back(1000000001);
	for (int i = 0; i < n; i++)
	{
		if (v.back() < arr[i])
		{
			v.push_back(arr[i]);
			dp[i] = v.size() - 1;
		}
		else
			v[dp[i] = lower_bound(v.begin(), v.end(), arr[i])-v.begin()] = arr[i];
	}
	printf("%d\n", v.size());
	temp = v.size()-1;
	for (int i = n-1; i >=0; i--)
	{
		if (dp[i] == temp)
		{
			st.push_back(arr[i]);
			temp--;
		}
	}
	while (!st.empty())
	{
		printf("%d ", st.back());
		st.pop_back();
	}
	scanf_s("%d", &n);
	return 0;
}