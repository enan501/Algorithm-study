#include <iostream>
using namespace std;
int k, s[13],d[6];
void dfs(int c,int n)
{
	d[c] = n;
	if (c == 5)
	{
		for (int i = 0; i < 6; i++)
			cout << s[d[i]] << " ";
		cout << '\n';
		return;
	}
	for (; n < k-1; n++)
		dfs(c + 1, n+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	while (1)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
			cin >> s[i];
		for (int i = 0; i < k - 5; i++)
			dfs(0, i);
		cout << '\n';
	}
	return 0;
}