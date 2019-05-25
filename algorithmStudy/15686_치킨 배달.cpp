#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, arr[51][51],total,mmin=99999999,dist = 99999999;
bool leftChicken[13];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (arr[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < m; i++)
		leftChicken[i] = true;
	do
	{
		total = 0;
		for (int i = 0; i < house.size(); i++)
		{
			dist = 99999999;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (leftChicken[j])
					dist = min(dist,abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
			}
			total += dist;
		}
		mmin = min(mmin, total);
	} while (prev_permutation(leftChicken, leftChicken + chicken.size()));
	cout << mmin;
	return 0;
}