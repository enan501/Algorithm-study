#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sum;
vector<int> v;
int main()
{
	v.resize(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	for (int i = 0; i < 9; i++)
		for (int j = i+1; j < 9; j++)
		{
			if (sum - v[i] - v[j] == 100)
			{
				v.erase(v.begin() + j);
				v.erase(v.begin() + i);
				sort(v.begin(), v.end());
				for (int i = 0; i < 7; i++)
					cout << v[i] << '\n';
				return 0;
			}
		}
}