#include<iostream>
#include<queue>
using namespace std;
int n,k,i,arr[100001];
queue<int> q;
int main(void)
{
	cin >> n >> k;
	q.push(n);
	if (n >= k)
	{
		cout << n - k;
		return 0;
	}
	while (!q.empty() && i!=k)
	{
		i = q.front();
		q.pop();
		if (i > 0 && !arr[i - 1])
		{
			arr[i - 1] = arr[i] + 1;
			q.push(i - 1);
		}
		if(i<k && !arr[i + 1])
		{
			arr[i + 1] = arr[i] + 1;
			q.push(i + 1);
		}
		if(i<=50000 && !arr[i*2])
		{
			arr[i*2] = arr[i] + 1;
			q.push(i * 2);
		}
	}
	cout << arr[i];
	return 0;
}