//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int arr[11][11], cnt, rect[6], temp;
//bool check[11][11];
//vector<pair<int, int>> v;
//
//void func(int d) {
//	if(v.size() == d)
//	if (check[v[d].first][v[d].second]) return;
//
//}
//int main() {
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++)
//			cin >> arr[i][j];
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (arr[i][j]) {
//				temp = 0;
//				for (int s = 2; s <= 5; s++) {
//					for (int dx = 0; dx < s; dx++)
//						for (int dy = 0; dy < s; dy++)
//							temp += arr[i + dy][j + dx];
//					if (temp == s * s) arr[i][j] = s;
//				}
//				v.push_back(make_pair(i, j));
//			}
//		}
//	}
//	func(0);
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			for (int s = arr[i][j]; s > 0; s--) {
//				if (rect[s]) {
//					rect[s]--;
//
//				}
//			}
//		}
//	}
//
//	return 0;
//}