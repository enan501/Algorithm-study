#include<iostream>
using namespace std;
int n, s[51][3], arr[51][51];
bool d[51];

int func(int k)
{
	if (k == n)
	{
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[k][i])
		{
			d[i] = 1;
			for (int j = i + 1; j < n; j++)
			{
				 if (arr[k][j])
				{
					d[j] = 1;
					func(k + 1);
					d[j] = 0;
				}
			}
			d[i] = 0;
		}
	}
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)  
		{
			if (s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]) arr[i][j] = 1;
			else if (s[i][0] <= s[j][0] && s[i][1] <= s[j][1] && s[i][2] <= s[j][2]) arr[j][i] = 1;
		}
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = j; k < n; k++)
			{

			}
		}
	return 0;
}