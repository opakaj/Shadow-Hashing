#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

void echo(string& str, char i, char j, int n)
{
	while (1)
	{
		if ((i == 'b') && (j == 'b'))
		{
			str[n] = 'e';
			str[n + 2] = '1';
			break;
		}

		else if ((i == 'b') && (j == 'd'))
		{
			str[n + 2] = '1';
			break;
		}

		else if ((i == 'd') && (j == 'd'))

		{
			str[n] = '8';
			str[n + 2] = 'e';
			break;
		}

		else if ((i == 'd') && (j == 'b'))
		{
			str[n] = '0';
			str[n + 2] = '9';
			break;
		}

		else
			break;
	}
}
