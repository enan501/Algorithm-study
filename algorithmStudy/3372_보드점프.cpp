#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, arr[101][101],up, num, _min, i, alen, blen;
string dp[101][101];
void add(string& a, string b)
{
	up = 0, num = 0, _min = 0, i = 0;
	alen = a.length(), blen = b.length();
	_min = min(alen, blen);
	for (i = 0; i < _min; i++)
	{
		if ((num = a[alen - i - 1] - '0' + b[blen - i - 1] - '0' + up) > 9)
		{
			a[alen - i-1] = '0' + num - 10;
			up = 1;
		}
		else
		{
			a[alen - i-1] = '0' + num;
			up = 0;
		}
	}
	if (alen < blen)
	{
		_min = blen - alen;
		for (int j = 0; j < _min; j++)
		{
			if ((num = b[blen - i++ - 1] - '0' + up) > 9)
			{
				a = to_string(num-10).append(a);
				up = 1;
			}
			else
			{
				a = to_string(num).append(a);
				up = 0;
			}
		}
	}
	else if (alen > blen)
	{
		_min = alen - blen;
		for (int j = 0; j < _min; j++)
		{
			if ((num = a[alen - i++ - 1] - '0' + up) > 9)
			{
				a[alen - i] = '0' + num - 10;
				up = 1;
			}
			else
			{
				a[alen - i] = '0' + num;
				up = 0;
			}
		}
	}
	if (up > 0)
		a = to_string(1).append(a);

}

string dfs(int x, int y)
{
	string s = "0";
	if (y + arr[y][x] < n)
	{
		if (dp[y + arr[y][x]][x] != "-1") add(s,dp[y + arr[y][x]][x]);
		else if (arr[y][x]) add(s,dfs(x, y + arr[y][x]));
	}
	if (x + arr[y][x] < n)
	{
		if (dp[y][x + arr[y][x]] != "-1") add(s,dp[y][x + arr[y][x]]);
		else if (arr[y][x]) add(s,dfs(x + arr[y][x], y));
	}
	return dp[y][x] = s;
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = "-1";
		}
	}
	dp[n - 1][n - 1] = "1";
	dfs(0, 0);
	cout << dp[0][0];
	return 0;
}