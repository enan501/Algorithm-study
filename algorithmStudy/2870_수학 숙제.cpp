#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
string s, str;
vector<string> v;
bool cmp(string& a, string& b)
{
	if (a.size() > b.size()) return 0;
	else if (b.size() > a.size()) return 1;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i]) return 0;
		else if (b[i] > a[i]) return 1;
	}
	return 0;
}
void push(string& str)
{
	while (!str.empty())
	{
		if (str[0] == '0')
			str.erase(0, 1);
		else
			break;
	}
	if (str.empty()) v.push_back("0");
	else v.push_back(str);
	str.clear();
}
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0;j<s.size();j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
				str += s[j];
			else if (!str.empty())
				push(str);
		}
		if (!str.empty())
			push(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}