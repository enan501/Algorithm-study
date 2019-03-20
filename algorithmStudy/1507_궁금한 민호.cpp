#include<iostream>
using namespace std;
int n, arr[20][20], s;
bool checked[20][20];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != k && k != j && i != j)
				{
					if (arr[i][k] + arr[k][j] == arr[i][j])
						checked[i][j] = 1;
					else if (arr[i][k] + arr[k][j] < arr[i][j])
					{
						printf("-1");
						return 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (!checked[i][j]) s += arr[i][j];
	cout << s;
	return 0;
}