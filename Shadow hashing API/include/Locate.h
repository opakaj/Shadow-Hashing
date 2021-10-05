#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

int locate(string& str, char x, char y, char z = ' ')
{
    int n = 0, v = 0;

    auto i2 = begin(str);
    auto i3 = next(i2);

    while ((i2 < prev(end(str))) && (i3 < end(str)) && (n <= 8))
    {
        if (((*i2 == x) && (*i3 == y)) || ((*i2 == x) && (*i3 == z)))
        {
            v = 0;
            break;
        }

        if ((*i2 == 48) && (*i3 == 48))
        {
            if (z != ' ')
            {
                str[n] = x;
                str[n + 1] = z;
                v = 1;
                //cout<<"im in the if!!"<<endl;
                break;
            }
            else
            {
                str[n] = x;
                str[n + 1] = y;
                v = 1;
                //cout<<"Im in the else "<<endl;
                break;
            }
        }

        advance(i2, 2);
        advance(i3, 2);
        n += 2;
    }

    //cout<<str<<endl;
    return v;
}


