#include <iostream>
#include <algorithm>
using namespace std;
int n, t[1001], dp[1001]; //dp에 i일부터~ 퇴사일동안 받을 수 있는 최대 보상을 저장
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n;	
	for(int i=0;i<n;i++)
		cin >> t[i] >> dp[i]; //기간을 t에 저장 / dp에는 이 날짜에 상담 했을때의 보상금액 저장
	for (int i = n; i >= 0; i--) //맨뒤에서부터
		if (i + t[i] > n) dp[i] = dp[i+1]; // 종료일이 퇴사날을 넘어가면 뒤에거 그대로 dp에 저장
		else dp[i] = max(dp[i] + dp[i + t[i]], dp[i + 1]); //이날짜에 상담하면 얻는 이익, 안했을 때 이익을 비교
	cout << dp[0];	
	return 0;
}