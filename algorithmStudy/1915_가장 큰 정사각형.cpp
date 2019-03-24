#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m,arr[1001][1001],mmax;
int main(void)
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d",&arr[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (arr[i][j] && arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1])
				arr[i][j] = min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1]) + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mmax = max(mmax, arr[i][j]);
	printf("%d",mmax*mmax);
	return 0;
}