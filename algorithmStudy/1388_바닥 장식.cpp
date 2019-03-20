#include<iostream>
using namespace std;
int n, m,cnt;
char arr[101][101];
bool flag;
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!flag && arr[i][j] == '-')
			{
				flag = true;
				cnt++;
			}
			else if(flag && arr[i][j] == '|')
				flag = false;
		}
		flag = false;
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (!flag && arr[i][j] == '|')
			{
				flag = true;
				cnt++;
			}
			else if (flag && arr[i][j] == '-')
				flag = false;
		}
		flag = false;
	}
	cout << cnt;
	return 0;
}