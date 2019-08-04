/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cmath>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n=0,c=0,m=0,rootn=0;
		cin >> n;
		rootn = sqrt(n);
		for (int i = 2; i <= rootn; i++)
		{
			m = n;
			while (m >= i)
			{
				c = m % i;
				m /= i;
				if (c != m % i)
					break;
			}
			if (m <i && c == m%i )
			{
				Answer = i;
				break;
			}
		}
		if (!Answer)
		{
			for (int i = rootn; i > 0; i--)
			{
				if (n%i == 0 && n/i-1 > i)
				{
					Answer = n/i-1;
					break;
				}
			}
			if(!Answer) Answer = n - 1;
		}
		if (n == 1) Answer = 2;
		if (n == 2) Answer = 3;
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
