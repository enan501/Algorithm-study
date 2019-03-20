#include<stdio.h>
#include<vector>
using namespace std;
bool visit[25] = { false };
bool parr[5][5] = { false };
char arr[5][5] = { 0 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> list;

int dfs(int number)
{
	int count = 1;
	parr[number / 5][number % 5] = false;
	for (int i = 0; i < 4; i++)
	{
		if (number / 5 + dy[i] < 0 || number / 5 + dy[i] > 4 || number % 5 + dx[i] < 0 || number % 5 + dx[i] > 4)
			continue;
		if (parr[number / 5 + dy[i]][number % 5 + dx[i]])
			count += dfs(number + dy[i] * 5 + dx[i]);
	}
	return count;
}
bool check()
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		parr[list[i] / 5][list[i] % 5] = true;
		if (arr[list[i] / 5][list[i] % 5] == 'S')
			count++;
	}
	return count >= 4 && dfs(list[0]) == 7;
}
int func(int number)
{
	int count = 0;
	list.push_back(number);
	visit[number] = true;
	if (list.size() == 0)
	{
		if (check())
			count++;
		list.pop_back();
	}
	if (number == 24)
		list.pop_back();
	else
	{
		for (int i = number; i < 25; i++)
		{
			if (!visit[number + 1])
				count += func(number + 1);
		}
	}
	return count;
}

int main(void)
{
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf_s("%c", &arr[i][j]);
		}
	}
	printf("%d", func(0));
	getchar();
	getchar();	getchar();	getchar();	getchar();
	scanf_s("%d", &n);
	return 0;
}