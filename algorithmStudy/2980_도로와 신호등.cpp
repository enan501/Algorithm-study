#include<iostream>
using namespace std;
int n,l, r[101], g[101], d, time, rtime, c;
bool arr[1001];
int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> d >> r[i] >> g[i];
		arr[d] = 1; //�ش���ġ�� ��ȣ���� �ִ��� ������
	}
	for (int i = 1; i < l; i++) {
		time++;
		if (arr[i]) {
			rtime = time % (r[c] + g[c]);  
			if (rtime < r[c]) //�������̸�
				time += (r[c] - rtime); //�ʷϺҵɶ����� �����ð� ����
			c++; //���� ��ȣ���� ����Ŵ
		}
	}
	cout << time+1;
	return 0;
}