#include <iostream>
#include <vector>
using namespace std;
int n, tmp, arr[100000];
vector<int*> parr;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		parr.push_back(&arr[i]);

	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		*parr[tmp] = i;
		parr.erase(parr.begin()+tmp);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i]<<'\n';
	return 0;
}