#include<iostream>
#include<algorithm>
using namespace std;
int n,d[50];
char arr[50][50];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)continue;
			if (arr[i][j] == 'N')
			{
				for (int c = 0; c < n; c++)
					if (arr[i][c] == 'Y' && arr[j][c] == 'Y')
					{
						arr[i][j] = arr[j][i] = 'S';
						d[i]++;
						break;
					}
			}
			else
				d[i]++;
		}
	}
	cout << *max_element(d, d + 50);
	return 0;
}