#include<iostream>
#include<algorithm>
using namespace std;
int n,ssum,lsum,d,mmin=99999999, arr[20][20];
int team[20];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n / 2; i++)
		team[i] = 1;
	do
	{
		ssum = lsum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i!=j && team[i] && team[j]) ssum += arr[i][j];
				else if (i!=j && !team[i] && !team[j]) lsum += arr[i][j];
		if (ssum > lsum) d = ssum - lsum;
		else d = lsum - ssum;
		if (mmin > d) mmin = d;
	}while (prev_permutation(team, team + n));
	cout << mmin;
	return 0;
}