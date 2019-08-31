#include<iostream>
using namespace std;
int n, dp[3][17][17];
bool arr[17][17];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int j = 1; j < n; j++) { //ù��°��
		if (arr[0][j]) break;
		else dp[0][0][j] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			//dp[shape][i][j] = ����ĭ�� shape������� ���� ����Ǽ�(shape 0=����, 1=����, 2�밢��)
			if (!arr[i][j]) {
				//���ʿ��� ���� ���� ����, �밢���� ���. ������ ����
				dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
				//������ ���� ���� ����, �밢���� ���. ������ ����
				dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
				//���������� ���� ���� shape ��� ����. ������ �밢��
				if(!arr[i-1][j] && !arr[i][j-1])
					dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			}
		}
	}
	cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1];
	return 0;
}