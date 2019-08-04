#include <iostream>
using namespace std;
int N, m, M, T, R, heartbeat,cnt;
int main(void) {
	cin >> N >> m >> M >> T >> R;
	if (m + T > M)
		cnt = -1;
	else {
		heartbeat = m;
		for (int i = 0; i < N; cnt++) {
			if (heartbeat + T <= M) {
				heartbeat += T;
				i++;
			}
			else {
				if (heartbeat - R < m)
					heartbeat = m;
				else
					heartbeat -= R;
			}
		}
	}
	cout << cnt;
	return 0;
}