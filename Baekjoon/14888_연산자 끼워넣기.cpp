#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[101], op[100],temp,j,mmin=1000000000,mmax=-1000000000;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
	{
		cin >> temp;
		for (temp+=j; j < temp; j++)
			op[j] = i;
	}
	do
	{
		temp = arr[0];
		for (int i = 0; i < n - 1; i++)
		{
			if (op[i] == 0) temp += arr[i + 1];
			else if (op[i] == 1)temp -= arr[i + 1];
			else if (op[i] == 2)temp *= arr[i + 1];
			else temp /= arr[i + 1];
		}
		mmin = min(mmin, temp);
		mmax = max(mmax, temp);
	} while (next_permutation(op, op + n-1));
	cout << mmax << '\n' << mmin;
	return 0;
}