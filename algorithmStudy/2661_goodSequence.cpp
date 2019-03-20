#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
vector<int> arr;
int n = 0;

bool func()
{
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < arr.size() / 2 + 1; j++)
		{
			int cnt = 0;
			for (int m = 1; m < j + 1; m++)
			{
				if (arr[arr.size() - m] == arr[arr.size() - m - j])
					cnt++;
				else
					break;
			}
			if (cnt == j)
				return false;
		}
		if (arr.size() == n) return true;
		arr.push_back(i);
		if (func())
		{
			st.push(i);
			return true;
		}
		else
			arr.pop_back();
		
	}
	return false;
}

int main(void)
{

	scanf_s("%d", &n);
	//for (int i = 1; i < 40; i++)
	//{
	//	n = i;
		func();
		while (!st.empty())
		{
			printf("%d", st.top());
			st.pop();
			arr.pop_back();
		}
		printf("\n");
		
	//}
	scanf_s("%d", &n);
	return 0;
}