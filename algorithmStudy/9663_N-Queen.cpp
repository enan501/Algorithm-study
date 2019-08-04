#include<iostream>
using namespace std;
int n, ans;
bool row[15], ld[31], rd[31];
void func(int col)
{
	for (int i = 0; i < n; i++)
	{
		if (!row[i] && !rd[col+i] && !ld[col-i+n-1])
		{
			row[i] = rd[col + i] = ld[col - i + n-1] = 1;
			if (col == n-1) ans++;
			else func(col + 1);
			row[i] = rd[col + i] = ld[col - i + n-1] = 0;
		}
	}
}
int main(void)
{

	cin >> n;
	func(0);
	cout << ans;
	return 0;
}