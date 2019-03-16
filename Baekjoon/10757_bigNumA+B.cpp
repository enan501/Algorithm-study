#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

string a,b;
stack<int> st;
int main(void)
{
	int up = 0, num = 0, _min = 0, i = 0;
	cin >> a >> b;
	int alen = a.length(), blen = b.length();
	_min = min(alen, blen);
	for (i = 0; i < _min; i++)
	{
		if ((num = a[alen-i - 1] - '0' + b[blen-i - 1] - '0' + up) > 9)
		{
			st.push(num - 10);
			up = 1;
		}
		else
		{
			st.push(num);
			up = 0;
		}
	}
	if (alen < blen)
	{
		_min = blen - alen;
		for (int j = 0; j < _min; j++)
		{
			if ((num = b[blen - i++ -1] - '0' + up) > 9)
			{
				st.push(num - 10);
				up = 1;
			}
			else
			{
				st.push(num);
				up = 0;
			}
		}
	}
	else if(alen > blen)
	{
		_min = alen - blen;
		for (int j = 0; j < _min; j++)
		{
			if ((num = a[alen - i++ - 1] - '0' + up) > 9)
			{
				st.push(num - 10);
				up = 1;
			}
			else
			{
				st.push(num);
				up = 0;
			}
		}
	}
	if (up > 0)
		st.push(1);
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	return 0;
}