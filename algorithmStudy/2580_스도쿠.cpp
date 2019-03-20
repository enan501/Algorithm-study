//#include <iostream>
//#include <vector>
//using namespace std;
//int arr[9][9];
//vector<int> vx, vy;
//bool flag;
//
//void dfs(int n)
//{
//	if (n == vx.size())
//	{
//		flag = 1;
//		return;
//	}
//	bool num[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	for (int i = 0; i < 9; i++)
//		num[arr[vy[n]][i]] = num[arr[i][vx[n]]] = num[arr[(vy[n] / 3) * 3 + i/3][(vx[n] / 3) * 3 + i%3]] = 1;
//
//	for (int i = 1; i < 10; i++)
//	{
//		if (!num[i])
//		{
//			arr[vy[n]][vx[n]] = i;
//			dfs(n + 1);
//			if (flag) return;
//		}
//	}
//	arr[vy[n]][vx[n]] = 0;
//}
//int main(void)
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			cin >> arr[i][j];
//			if (arr[i][j] == 0)
//			{
//				vx.push_back(j);
//				vy.push_back(i);
//			}
//		}
//	}
//	dfs(0);
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//			cout << arr[i][j] << " ";
//		cout << '\n';
//	}
//	return 0;
//}
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int arr[9][9];
vector<int> vx, vy;
void dfs(int n)
{
	if (n == vx.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << '\n';
		}
		exit(0);
	}
	bool num[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 9; i++)
		num[arr[vy[n]][i]] = num[arr[i][vx[n]]] = num[arr[(vy[n] / 3) * 3 + i / 3][(vx[n] / 3) * 3 + i % 3]] = 1;
	for (int i = 1; i < 10; i++)
	{
		if (!num[i])
		{
			arr[vy[n]][vx[n]] = i;
			dfs(n + 1);
		}
	}
	arr[vy[n]][vx[n]] = 0;
}
int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				vx.push_back(j);
				vy.push_back(i);
			}
		}
	}
	dfs(0);
	return 0;
}