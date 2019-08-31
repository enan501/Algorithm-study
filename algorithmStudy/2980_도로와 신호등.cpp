#include<iostream>
using namespace std;
int n,l, r[101], g[101], d, time, rtime, c;
bool arr[1001];
int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> d >> r[i] >> g[i];
		arr[d] = 1; //해당위치에 신호등이 있는지 없는지
	}
	for (int i = 1; i < l; i++) {
		time++;
		if (arr[i]) {
			rtime = time % (r[c] + g[c]);  
			if (rtime < r[c]) //빨간불이면
				time += (r[c] - rtime); //초록불될때까지 남은시간 더함
			c++; //다음 신호등을 가리킴
		}
	}
	cout << time+1;
	return 0;
}