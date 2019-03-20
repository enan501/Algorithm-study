#include<stdio.h>
#include<algorithm>
using namespace std;
int n, arr[500][500];
int main(void)
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d",&arr[i][j]);
	for (int i = 1; i < n; i++)
	{
		arr[i][0] += arr[i - 1][0];
		arr[i][i] += arr[i - 1][i - 1];
		for (int j = 1; j < i; j++)
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
	}
	printf("%d",*max_element(arr[n - 1], arr[n - 1] + n));
	return 0;
}