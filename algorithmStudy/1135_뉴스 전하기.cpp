#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, temp;
vector<vector<pair<int,int>>> v;
int func(int i) {
	int s=0;
	if (v[i].empty()) return 0;
	for (int j = 0; j < v[i].size(); j++)
		if (v[i][j].first == 0) v[i][j].first = func(v[i][j].second)+1;
	sort(v[i].begin(), v[i].end(),greater<pair<int,int>>());
	for (int j = 1; j < v[i].size(); j++)
		v[i][j].first = max(v[i][j-1].first, v[i][j].first + j);
	return v[i].back().first;
}

int main(void) {
	cin >> n>> temp;
	v.resize(n);
	for (int i = 1; i < n; i++) {
		cin >> temp;
		v[temp].push_back(make_pair(0,i));
	}
	cout<<func(0);
	return 0;
}