#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

void un_echo(string& str)
{
	int n = 0;
	auto i = begin(str);
	auto j = next(next(i));

	while (n < 5)
	{
		if ((*i == 'e') && (*j == '1'))
		{
			str[n] = 'b';
			str[n + 2] = 'b';
		}

		else if ((*i == 'b') && (*j == '1')) str[n + 2] = 'd';

		else if ((*i == '8') && (*j == 'e'))
		{
			str[n] = 'd';
			str[n + 2] = 'd';
		}

		else if ((*i == '0') && (*j == '9'))
		{
			str[n] = 'd';
			str[n + 2] = 'b';
		}

		advance(i, 2);
		advance(j, 2);
		n += 2;
	}
}