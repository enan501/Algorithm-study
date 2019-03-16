#include <stdio.h>
#include <string.h>
using namespace std;
long long* arr = NULL;

int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	arr = new long long[n];
	memset(arr, -1, sizeof(long long)*n);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i - 1] == -1)
			arr[i - 1] = arr[i - 2] + arr[i - 3];
	}
	printf("%lld", arr[n-1]);
	scanf_s("%d", &n);
	return 0;
}