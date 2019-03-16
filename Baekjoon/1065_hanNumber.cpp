#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n = 0, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i < 100)
			count++;
		else if (i / 100 - (i / 10 - i / 100 * 10) == (i / 10 - i / 100 * 10) - (i - i / 10 * 10))
			count++;
	}
	cout << count;
	return 0;
}

