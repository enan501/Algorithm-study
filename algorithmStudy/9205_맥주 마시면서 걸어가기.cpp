#include<iostream>
#include<cmath>
using namespace std;
int t, n,x[103], y[103], arr[103][103];;
int main(void)
{
	cin >> t;
	while (t--)
	{
		cin >> n >> x[0] >> y[0];
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i] >> y[i];
			for (int j = 0; j < i; j++)
				arr[i][j] = arr[j][i] = (abs(y[i] - y[j]) + abs(x[i] - x[j]) <= 1000);
		}
		cin >> x[n+1] >> y[n+1];
		for (int j = 0; j < n+1; j++)
			arr[n + 1][j] = arr[j][n + 1] = (abs(y[n+1] - y[j]) + abs(x[n+1] - x[j]) <= 1000);
		for (int k = 0; k < n + 2; k++)
			for (int i = 0; i < n + 2; i++)
				for (int j = 0; j < n + 2; j++)
					if (k != i && k != j && i != j && arr[i][k] && arr[k][j]) arr[i][j] = 1;
		if (arr[0][n + 1])
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	return 0;
}