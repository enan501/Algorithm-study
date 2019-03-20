#include<iostream>
#include<string>
using namespace std;
long long gcd(long long son, long long mom)
{
	long long temp = 0;
	while (son != 0)
	{
		temp = mom%son;
		mom = son;
		son = temp;
	}
	return mom;
}
int main(void)
{
	long long i = 0, intPart = 0, decPart = 0, nCirclePart = 0, g = 1, mom = 1, nCircle = 1;
	bool isM = false;
	string str;
	cin >> str;
	if (str[0] == '-')
	{
		isM = true;
		str = str.substr(1, str.length()-1);
	}
	for (i = 0; i < str.length()-1; i++)
	{
		if (str[i] == '.')
			break;
	}
	if (i == str.length()-1) 
		cout << str <<"/1";
	else
	{
		intPart = atoll(str.substr(0, i).c_str());
		str = str.substr(i + 1, str.length()-i-1);
		
		for (i = 0; i < str.length()-1; i++)
		{
			if (str[i] == '(')
				break;
		}
		if (i == str.length()-1 || atoll(str.substr(i + 1, str.length() - i - 2).c_str()) == 0)
		{
			decPart = atoll(str.substr(0,i+1).c_str());
			while (mom <= decPart) mom *= 10;
		}
		else
		{
			nCirclePart = atoll(str.substr(0, i).c_str());
			decPart = atoll(str.substr(0,i).append(str.substr(i+1,str.length()-i-2)).c_str()) - atoll(str.substr(0,i).c_str());
			if (decPart != 0) while(mom <= decPart) mom *= 10;
			if (nCirclePart != 0) while (nCircle <= nCirclePart) nCircle *= 10;
			mom -= nCircle;
		}
		if (decPart == 0) mom = 1;
		g = gcd(decPart, mom);
		decPart /= g;
		mom /= g;
		if (isM) cout << '-';
		cout << decPart + intPart * mom << "/" << mom;
	}
	return 0;
}