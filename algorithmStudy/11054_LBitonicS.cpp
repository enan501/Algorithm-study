#include <stdio.h>
using namespace std;
int main(void)
{
	int n = 0, lbs = 0;
	int* arr = NULL;
	int* dpf = NULL;
	int* dpb = NULL;
	scanf_s("%d", &n);
	arr = new int[n];
	dpb = new int[n];
	dpf = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) //앞에서부터 LIS 구함
	{
		dpf[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dpf[j] + 1 > dpf[i])
				dpf[i] = dpf[j] + 1; //dpf에는 앞에서부터 i자리까지 LIS 크기 저장
		}
	}
	for (int i = n-1; i >= 0 ; i--) //뒤에서부터 LIS 구함
	{
		dpb[i] = 1;
		for (int j = n-1; j > i; j--)
		{
			if (arr[j] < arr[i] && dpb[j] + 1 > dpb[i])
				dpb[i] = dpb[j] + 1; //dpb에서는 뒤에서 i번째(n-1~ n-1-i) 까지 LIS 크기 저장
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (lbs < dpf[i] + dpb[i])
			lbs = dpf[i] + dpb[i]; //i자리 기준으로 앞뒤 LIS 더해서 최대값
	}	
	printf("%d", lbs-1); //i번째는 두번 포함되므로 1 빼줌
	scanf_s("%d", &n);
	return 0;
}