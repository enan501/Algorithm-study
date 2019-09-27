#include <iostream>
using namespace std;
int n, m, l, c, cnt, arr[1001];
int main() {
	cin >> n >> m >> l;
	for (; ++arr[c] < m ;cnt++)
		if (arr[c] % 2) c = (n + c - l) % n;
		else c = (c + l) % n;
	cout << cnt;
	return 0;
}