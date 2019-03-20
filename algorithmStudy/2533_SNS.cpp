#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr[1000000];
int *dp = NULL;
int n = 0, ea = 0;
bool func(int root)
{
	bool isea = false;
	for (int i = 0; i < arr[root].size(); i++)
	{
		if (!func(arr[root][i]))
			isea = true;
	}
	if (isea) ea++;
	return isea;
}

int main(void)
{
	int p = 0, c = 0;
	scanf_s("%d", &n);
	dp = new int[n];
	memset(dp, 0, sizeof(int)*n);
	for (int i = 0; i < n-1; i++)
	{
		scanf_s("%d %d", &p, &c);
		arr[p - 1].push_back(c - 1);
	}
	func(0);
	printf("%d", ea);
	scanf_s("%d", &n);
	return 0;

}