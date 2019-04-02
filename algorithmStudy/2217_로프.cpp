#include<stdio.h>
#include<algorithm>
using namespace std;
int n, ans, arr[100001];
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		ans = max(ans, arr[i] * (n - i));
	printf("%d",ans);
	return 0;
}