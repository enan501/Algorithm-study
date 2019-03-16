//#include<stdio.h>
//#include<queue>
//using namespace std;
//int main(void)
//{
//	priority_queue<int> pq;
//	int n = 0, m = 0, sum = 0;
//	bool isPossible = false;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &m);
//		pq.push(m);
//		sum += m;
//	}
//	if (sum == n * (n - 1) / 2)
//	{
//		isPossible = true;
//		m = n-1;
//		sum = 0;
//		while(!pq.empty())
//		{
//			if (pq.top() > m)
//			{
//				if (pq.top() <= m + sum)
//					sum -= (pq.top() - m );
//				else
//				{
//					isPossible = false;
//					break;
//				}
//			}
//			if (pq.top() < m)
//				sum += m - pq.top();
//			pq.pop();
//			m--;
//		}
//	}
//	if (isPossible) printf("1");
//	else printf("-1");
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int m[10001];
int d[10001][10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int v = a[i]; // i번째 팀의 승점
		for (int k = 1; k <= i; k++) {
			if (d[i][k] == 1) v--; // 이전 경기에서 얻은 승점만큼 제거
		}
		for (int j = i + 1; j <= n; j++) {
			if (v > 0) { // 승점이 남아있는 경우 (i번째 팀이 이김)
				d[i][j] = 1;
				v--;
			}
			else { // 승점이 없는 경우 (상대 팀이 이김)
				d[j][i] = 1;
			}
		}
	}
	// m 배열에 최종 점수 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << " ";
			m[i] += d[i][j];
		}
		cout << '\n';
	}
	sort(m + 1, m + n + 1);
	bool check = true;
	// 기존 정렬된 배열과 새로 생성한 배열이 같으면 유효한 경기였다고 판단
	for (int i = 1; i <= n; i++) {
		if (a[i] != m[i]) check = false;
	}
	cout << (check ? 1 : -1) << '\n';
	return 0;
}
