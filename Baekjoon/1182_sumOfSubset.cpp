#include <stdio.h>

int* arr;
int s = 0, n = 0, num = 0;
void func(int i,int sum) //각 원소마다 부분집합에 포함o/x 두가지 경우가 있으므로 모든 i번째 원소에서 두가지 경우를 조사하면 된다 
{
	if (sum + arr[i] == s) //지금까지 합에서 현재 원소 더해서 원하는 값인지 검사
	{
		num++; //맞으면 1추가
	}
	if (i < n - 1) { //마지막 원소 전까지
		func(i + 1, sum); //현재 원소 포함하지 않는 부분집합 검사
		func(i + 1, sum + arr[i]); //현재원소 포함하는 부분집합 검사
	}
}
int main(void)
{
	scanf_s("%d %d", &n, &s);
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	func(0, 0);
	printf("%d", num);
	scanf_s("%d",&n);
	return 0;
}

