#include<iostream>
using namespace std;
int arr[2000],a,b,sum;
int main(void)
{
	cin >> a >> b;
	for(int i = 1; sum <= b; i++) {
		for (int j = 1; j <= i; j++) {
			arr[sum + j] = arr[sum + j - 1] + i;
		}
		sum += i;
	}
	cout << arr[b] - arr[a-1];
	return 0;
}