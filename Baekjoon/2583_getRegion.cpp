#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool** arr = NULL;
int m = 0, n = 0;
int func(int i, int j) { //재귀적으로 상하좌우에 빈칸이 있으면 그 칸에서 다시 상하좌우 조사
	int count = 1;
	arr[i][j] = true; //조사한 칸은 값 변경해서 다시 조사하지 않게 함
	if (arr[i][j - 1] == false)
		count += func(i, j - 1);
	if (arr[i][j + 1] == false)
		count += func(i, j + 1);
	if (arr[i - 1][j] == false)
		count += func(i - 1, j);
	if (arr[i + 1][j] == false)
		count += func(i + 1, j);
	return count;
}
int main(void)
{
	int k = 0, col1 = 0, col2 = 0, row1 = 0, row2 = 0;
	vector<int> v;
	scanf_s("%d %d %d", &m, &n, &k);
	arr = new bool*[m + 2]; //상하좌우 맨 끝줄에 true인 영역 추가
	for (int i = 1; i < m + 1; i++)
	{
		arr[i] = new bool[n + 2];
		memset(arr[i], false, (n + 1) * sizeof(bool));
		arr[i][0] = true;
		arr[i][n + 1] = true;
	}
	arr[0] = new bool[n + 2];
	arr[m + 1] = new bool[n + 2]; 
	memset(arr[0], true, (n + 2) * sizeof(bool));
	memset(arr[m + 1], true, (n + 2) * sizeof(bool)); 
	for (int i = 0; i < k; i++) {
		scanf_s("%d %d %d %d", &row1, &col1, &row2, &col2);
		for (int j = col1 + 1; j < col2+1; j++) {
			for (int t = row1 + 1; t < row2+1; t++) {
				arr[j][t] = true;
			}
		}
	} // 여기까지 배열 초기설정

	for (int i = 0; i < m + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (arr[i][j] == false) {
				v.push_back(func(i, j)); //분할된 영역마다 넓이 값 계산해서 벡터에 저장
			}
		}
		printf("\n");
	}
	sort(v.begin(), v.end()); //정렬

	printf("%d\n", v.size()); //분리되는 영역이 몇개인지
	for (unsigned int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]); //정렬된 값 하나씩 출력(영역의 넓이)
	}
	scanf_s("%d", &n);
	return 0;
}