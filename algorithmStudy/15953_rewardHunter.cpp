#include <iostream>
#include <math.h>
using namespace std;
int arr[2][101];
int main(void)
{
	ios_base::sync_with_stdio(false);
	int t = 0, a=0, b=0, x = 0;
	cin >> t;
	for (int i = 1; i < 7; i++)
	{
		x += (i-1);
		for (int j = 1; j < i+1; j++)
		{
			if (i == 1)
				arr[0][j+x] = 500;
			if (i == 2)
				arr[0][j + x] = 300;
			if (i == 3)
				arr[0][j + x] = 200;
			if (i == 4)
				arr[0][j + x] = 50;
			if (i == 5)
				arr[0][j + x] = 30;
			if (i == 6)
				arr[0][j + x] = 10;
		}
	}
	for (int i = 1; i < 6; i++)
	{
		x = pow(2, i - 1);
		for(int j=x;j<x*2;j++)
			arr[1][j] = 512/x;
	}
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << (arr[0][a] + arr[1][b]) * 10000 << endl;
	}
	return 0;
}