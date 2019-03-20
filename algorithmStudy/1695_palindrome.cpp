#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int* arr = NULL;
int** dp = NULL;
int func(int front,int back) {
	if (front >= back) //모든 수를 조사하면 재귀 탈출
	{
		return 0;
	}
	if (dp[front][back] != -1) //이미 값이 계산되어서 저장되어있는 경우
		return dp[front][back];
	if (arr[front] != arr[back]) 
	{
		return dp[front][back] = min(func(front + 1, back), func(front, back - 1)) +1; //계산함과 동시에 dp배열에 저장해서 중복계산 방지
	}
	else
	{
		return dp[front][back] = func(front + 1, back - 1);//여기도 같음
	}
}
int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	arr = new int[n];
	dp = new int*[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[n];
		memset(dp[i], -1, n * sizeof(int));
		scanf_s("%d", &arr[i]);
	}
	printf("%d", func(0, n - 1));
	scanf_s("%d", &n);
	return 0;
}