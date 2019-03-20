//#include<iostream>
//using namespace std;
//int n, s[51][3], arr[51][51];
//bool d[51];
//int func(int k)
//{
//	if (k == n)
//	{
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (arr[k][i])
//		{
//			d[i] = 1;
//			for (int j = i + 1; j < n; j++)
//			{
//				if (arr[k][j])
//				{
//					d[j] = 1;
//					func(k + 1);
//					d[j] = 0;
//				}
//			}
//			d[i] = 0;
//		}
//	}
//}
//int main(void)
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> s[i][0] >> s[i][1] >> s[i][2];
//	for (int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)  
//		{
//			if (s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]) arr[i][j] = 1;
//			else if (s[i][0] <= s[j][0] && s[i][1] <= s[j][1] && s[i][2] <= s[j][2]) arr[j][i] = 1;
//		}
//	for (int i = 0; i<n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = j; k < n; k++)
//			{
//
//			}
//		}
//	return 0;
//}
#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<stack>
#include<stdio.h>
using namespace std;
vector<int> v;
stack<int> v2;
int arr[1000001];
int num[1000001];
int main() {
	int n;
	//int idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	num[arr[0]] = -1; // 트리 종료의 의미
	for (int i = 1; i < n; i++) {
		if (arr[i] > v.back()) {
			v.push_back(arr[i]);
			int idx = v.size() - 2; //하나 이전꺼 인덱스 저장
			num[arr[i]] = v[idx];
		}
		else
		{
			int idx2 = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx2] = arr[i];
			idx2--; //하나 이전꺼 인덱스 저장
			if (idx2 < 0) {
				num[arr[i]] = -1;
			}
			else
			{
				num[arr[i]] = v[idx2];
			}
		}

		/*8
		8 12 15 9 13 1 14 5*/
	}
	cout << v.size() << endl;
	int pt = v[v.size() - 1]; ///맨뒤에서부터 역추적
	while (pt != -1) {
		v2.push(pt);
		pt = num[pt];
	}

	while (!v2.empty()) {
		cout << v2.top() << " ";
		v2.pop();
	}
	cout << endl;

	return 0;
}