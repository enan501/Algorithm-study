#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int l = 0, c = 0, check = 0;
vector<char> arr;
vector<char> parr;
void func(int index)
{
	parr.push_back(arr[index]);
	if (parr.size() == l)
	{
		for (int i = 0; i < l; i++)
		{
			if (parr[i] == 'a' || parr[i] == 'e' || parr[i] == 'i' || parr[i] == 'o' || parr[i] == 'u')
				check++;
		}
		if (check > 0 && l - check >= 2)
		{
			for (int i = 0; i < l; i++)
			{
				printf("%c", parr[i]);
			}
			printf("\n");
		}
		check = 0;
		parr.pop_back();
		if (index == c - 1) parr.pop_back();
		return;
	}
	else if (index == c - 1)
	{
		parr.pop_back();
		parr.pop_back();
	}
	for (int i = index; i < c-1; i++)
	{
		func(i + 1);
	}
}
int main(void)
{

	char ch = 0;

	scanf_s("%d %d", &l, &c);
	getchar();
	for (int i = 0; i < c; i++)
	{
		scanf_s("%c", &ch);
		arr.push_back(ch);
		getchar();
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < c - l + 1; i++)
	{
		func(i);
	}
	scanf_s("%d", l);
	return 0;
}