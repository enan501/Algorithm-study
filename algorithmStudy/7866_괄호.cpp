#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int t, cnt, rcnt, answer, dp[1000001];
string str;
stack<int> st;
int main(void)
{
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cnt = 0;
		answer = 0;
		str = "";
		while (!st.empty()) st.pop();
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
				if (str[i] == '(')
					st.push(0);
				else if (str[i] == '{')
					st.push(1);
				else if (str[i] == '[')
					st.push(2);
				else if (str[i] == ')')
				{
					if (!st.empty() && st.top() == 0) {
						st.pop();
						dp[i] = 2 + dp[i - 1];
						if(i>=dp[i]) dp[i] += dp[i - dp[i]];
					}
				}
				else if (str[i] == '}')
				{
					if (!st.empty() && st.top() == 1) {
						st.pop();
						 dp[i] = 2 + dp[i - 1];
						 if (i >= dp[i])dp[i] += dp[i - dp[i]];
					}
				}
				else if (str[i] == ']')
				{
					if (!st.empty() && st.top() == 2) {
						st.pop();
						dp[i] = 2 + dp[i - 1];
						if (i >= dp[i]) dp[i] += dp[i - dp[i]];
					}
				}
		}
		answer = *max_element(dp, dp + str.size());

		cout << "#" << c << ' ';
		cout << answer << '\n';
		answer = 0;
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}