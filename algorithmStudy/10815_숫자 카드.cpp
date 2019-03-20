#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[500001], n, m, cur;
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i<m; i++)
	{
		scanf("%d", &cur);
		printf("%d ", binary_search(arr, arr + n, cur));
	}
	return 0;
}