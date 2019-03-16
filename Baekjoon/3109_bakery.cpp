#include<stdio.h>
using namespace std;

char** arr = NULL;
int r = 0, c = 0;

bool func(int x, int y)
{
	if (arr[y][x] == 'x')
		return false;
	if (x == c - 1)
		return true;
	for (int i = -1; i < 2; i++)
	{
		if (y + i < 0 || y + i == r)
			continue;
		if (func(x + 1, y + i))
		{
			arr[y][x] = 'x';
			return true;
		}
	}
	arr[y][x] = 'x';
	return false;
}
int main(void)
{
	int count = 0;
	scanf_s("%d %d", &r, &c);
	arr = new char*[r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new char[c];
		getchar();
		for (int j = 0; j < c; j++)
		{
			scanf_s("%c", &arr[i][j]);
		}
	}
	for (int i = 0; i < r; i++)
	{
		if (func(0, i))
			count++;
	}
	printf("%d", count);
	scanf_s("%d", &r);
	return 0;
}