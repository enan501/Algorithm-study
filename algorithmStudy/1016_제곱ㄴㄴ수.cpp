#include<stdio.h>
#include<cmath>
using namespace std;
long long int  _min, _max,rmax, j,ii;
int cnt;
bool arr[1000001];
int main(void)
{
	scanf_s("%lld %lld",&_min, &_max);
	rmax = (int)sqrt(_max);
	for (long long int i = 2; i <= rmax; i++)
	{
		ii = i * i;
		j = _min / ii;
		if (j*ii != _min) j++;
		for (; ii*j <= _max; j++)
			arr[ii*j - _min] = true;
	}
	for (int i = 0; i <= _max - _min; i++)
		if (!arr[i]) cnt++;
	printf("%d", cnt);
	return 0;
}