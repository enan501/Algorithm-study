#include<iostream>
#include<string>
using namespace std;
int front=1,back=1;
string str;
int main(void)
{
	cin >> str;
	for (int i = 0; i < str.length()-1; i++)
	{
		front *= (str[i] - '0');
		for (int j = i+1; j < str.length(); j++)
			back *= (str[j] - '0');
		if (front == back)
		{
			cout << "YES";
			return 0;
		}
		back = 1;
	}
	cout << "NO";
	return 0;
}