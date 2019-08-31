#include<iostream>
using namespace std;
int n, l, arr[2][101][101], ans;

int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[0][i][j];
			arr[1][j][i] = arr[0][i][j]; //세로용 배열 하나 더 만들었음
		}
	}
	for (int g = 0; g < 2; g++) {
		for (int i = 0; i < n; i++) {
			int j = 0;
			for (; j < n-1; j++) {
				if (arr[g][i][j + 1] == arr[g][i][j] - 1) { //내리막길
					int t = 1;
					for (; t < l; t++) //경사로 길이만큼 평평한 땅 있으면 l-1칸 건너뛰고 이동
						if (!(j + 1 + t < n && arr[g][i][j + 1 + t] == arr[g][i][j + 1])) break;
					if (t == l) j += (l-1);
					else break;
				}
				else if (arr[g][i][j + 1] == arr[g][i][j] + 1) { //오르막길
					int t = 1;
					for (; t < l; t++) //이 전에 경사로 길이만큼 평평한 땅 있었고
						if (!(j - t >= 0 && arr[g][i][j - t] == arr[g][i][j])) break;
					if (t != l) break;

					bool flag = false; //경사로가 겹치지 않으면 다음칸으로 이동
					for (t=l; t < l*2; t++) //(다시 경사로 길이만큼 높은 땅 있었는지 체크)
						if (j - t >= 0 && arr[g][i][j - t] > arr[g][i][j]) flag = true;
					if (flag) break; 
				}
				else if (arr[g][i][j + 1] != arr[g][i][j]) break; //평지
			}
			if (j == n-1) ans++; //마지막칸 까지 오면 정답에 1 추가
		}
	}
	cout << ans;
	return 0;
}