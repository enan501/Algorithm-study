#include<stdio.h>
#include<algorithm>
using namespace std;
int n, h, arr[2][100001],d[500001],m,cnt;
int arqq[2][10000000];
int main(void)
{
	scanf_s("%d %d",&n,&h);
	n /= 2;
	for (int i = 0; i < n; i++)
		scanf_s("%d %d", &arr[0][i], &arr[1][i]);
	sort(arr[0], arr[0] + n);
	sort(arr[1], arr[1] + n);
	for (int i = 1; i <= h; i++)
	{
		d[i] += n - (lower_bound(arr[0], arr[0] + n, i) - arr[0]);
		d[h-i+1] += n - (lower_bound(arr[1], arr[1] + n, i) - arr[1]);
	}
	m = *min_element(d + 1, d + h);
	for (int i = 1; i <= h; i++)
		if (d[i] == m) cnt++;
	printf("%d %d", m, cnt);
	return 0;
}
