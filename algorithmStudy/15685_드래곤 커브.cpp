#include <iostream>
#include <vector>
using namespace std;
int n, x, y, d, g, cnt, arr[101][101], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (n--){
		vector<int> v;
		cin >> x >> y >> d >> g;
		v.push_back(d);
		arr[y][x] = 1;
		arr[y += dy[d]][x += dx[d]] = 1; //���� 0�϶�
		for (int i = 1; i <= g; i++){ //���� 1���� g���� �ݺ�
			for (int j = v.size() - 1; j >= 0; j--){ //���Ϳ��� �ֱٰź��� �ϳ��� ����
				v.push_back(d = (v[j] + 1) % 4); //������⿡�� �ð�������� 90�� ȸ���� ������ ���Ϳ� ����
				arr[y += dy[d]][x += dx[d]] = 1; //�湮�� ��ǥ�� ���
			}
		}
	}
	for (int i = 0; i < 100; i++) //�簢�� ���� ã��
		for (int j = 0; j < 100; j++)
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) cnt++;
	cout << cnt;
	return 0;
}