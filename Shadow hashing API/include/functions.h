#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include "Locate.h"

using namespace std;

void odd_func(char i, char j, char x, string& a, string& b, string& c, string& d)
{
    if ((i >= 53 && i <= 57) && (j >= 53 && j <= 57)) //5-9 | 5-9
    {
        if ((i > j) && (locate(c, 'd', '1', 'e') == 1))
        {
            d[1] = i;
        }
        else if ((i > j) && (locate(c, 'a', '2') == 1))
        {
            a[2] = i;
        }
        else if ((j > i) && (locate(c, 'a', '0', 'f') == 1))
        {
            a[0] = i;
        }
        else if ((j > i) && (locate(c, 'd', '6') == 1))
        {
            d[6] = i;
        }
        else if (i == j && (locate(c, 'd', '4', 'c') == 1))
        {
            d[4] = i;

        }
        else if (i == j && (locate(c, 'd', '7') == 1))
        {
            d[7] = i;

        }
        else if (i == j && (locate(c, 'b', '1', 'e') == 1))
        {
            b[1] = i;

        }
        else if (i == j && (locate(c, 'a', '4', 'c') == 1))
        {
            a[4] = i;

        }
        else if (i == j && (locate(c, 'a', '1', 'e') == 1))
        {
            a[1] = i;

        }
        else
        {
            b[5] = i;
            locate(c, 'b', '5');
        }
    }

    else if ((i >= 53 && i <= 57) && (j >= 48 && j <= 52)) //5-9 | 0-4
    {
        if ((i - j > 3) && (x >= 48 && x <= 57) && (locate(c, 'a', '2') == 1))
        {
            a[2] = i;
        }
        else if ((i - j > 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(c, 'b', '1', 'e') == 1))
        {
            b[1] = i;
        }
        else if ((i - j <= 3) && (x >= 48 && x <= 57) && (locate(c, 'd', '7') == 1))
        {
            d[7] = i;
        }
        else if ((i - j <= 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(c, 'd', '4', 'c') == 1))
        {
            d[4] = i;
        }
        else
        {
            a[6] = i;
            locate(c, 'a', '6');
        }
    }

    else if ((i >= 48 && i <= 52) && (j >= 53 && j <= 57)) //0-4 | 5-9
    {
        if ((j - i > 3) && (x >= 48 && x <= 57) && (locate(c, 'a', '1', 'e') == 1))
        {
            a[1] = i;

        }
        else if ((j - i > 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(c, 'd', '6') == 1))
        {
            d[6] = i;

        }
        else if ((j - i <= 3) && (x >= 48 && x <= 57) && (locate(c, 'a', '0', 'f') == 1))
        {
            a[0] = i;

        }
        else if ((j - i <= 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(c, 'b', '6') == 1))
        {
            b[6] = i;

        }
        else
        {
            a[3] = i;
            locate(c, 'a', '3', 'a');
        }
    }


    else if ((i >= 48 && i <= 52) && (j >= 48 && j <= 52)) //0-4 | 0-4
    {
        if (i > j && (locate(c, 'a', '2') == 1))
        {
            a[2] = i;

        }
        else if (i > j && (locate(c, 'b', '4', 'c') == 1))
        {
            b[4] = i;

        }
        else if (j > i && (locate(c, 'b', '6') == 1))
        {
            b[6] = i;

        }
        else if (j > i && (locate(c, 'a', '0', 'f') == 1))
        {
            a[0] = i;

        }
        else if (i == j && (locate(c, 'a', '4', 'c') == 1))
        {
            a[4] = i;

        }
        else if (i == j && (locate(c, 'd', '1', 'e') == 1))
        {
            d[1] = i;

        }
        else if (i == j && (locate(c, 'a', '2') == 1))
        {
            a[2] = i;

        }
        else if (i == j && (locate(c, 'd', '4', 'c') == 1))
        {
            d[4] = i;

        }
        else if (i == j && (locate(c, 'b', '1', 'e') == 1))
        {
            b[1] = i;

        }
        else
        {
            d[2] = i;
            locate(c, 'd', '2');
        }
    }


    else if (((i >= 97 && i <= 102) || (i >= 65 && i <= 70)) && ((j >= 97 && j <= 102) || (j >= 65 && j <= 70))) //let | let
    {
        if (locate(c, 'a', '1', 'e') == 1)
        {
            a[1] = i;

        }
        else if (locate(c, 'b', '1', 'e') == 1)
        {
            b[1] = i;

        }
        else if (locate(c, 'd', '4', 'c') == 1)
        {
            d[4] = i;

        }
        else if (locate(c, 'a', '2') == 1)
        {
            a[2] = i;

        }
        else
        {
            d[5] = i;
            locate(c, 'd', '5');
        }
    }

    else if ((i >= 48 && i <= 57) && ((j >= 97 && j <= 102) || (j >= 65 && j <= 70))) // 0-9 | let
    {
        if (i >= 53 && (j == 101 || j == 102 || j == 98 || j == 69 || j == 70 || j == 66) && (locate(c, 'a', '0', 'f') == 1))
        {
            a[0] = i;

        }
        else if (i >= 53 && (j == 97 || j == 100 || j == 99 || j == 65 || j == 68 || j == 67) && (locate(c, 'b', '6') == 1))
        {
            b[6] = i;

        }
        else if (i < 53 && (j == 101 || j == 102 || j == 98 || j == 69 || j == 70 || j == 66) && (locate(c, 'a', '1', 'e') == 1))
        {
            a[1] = i;

        }
        else if (i < 53 && (j == 97 || j == 100 || j == 99 || j == 65 || j == 68 || j == 67) && (locate(c, 'd', '6') == 1))
        {
            d[6] = i;

        }
        else
        {
            b[3] = i;
            locate(c, 'b', '3', 'a');
        }
    }

    else if (((i >= 97 && i <= 102) || (i >= 65 && i <= 70)) && (j >= 48 && j <= 57)) // let | 0-9
    {
        if ((i == 101 || i == 102 || i == 98 || i == 69 || i == 70 || i == 66) && j >= 53 && (locate(c, 'b', '4', 'c') == 1))
        {
            b[4] = i;

        }
        else if ((i == 97 || i == 100 || i == 99 || i == 65 || i == 68 || i == 67) && j >= 53 && (locate(c, 'd', '1', 'e') == 1))
        {
            d[1] = i;

        }
        else if ((i == 101 || i == 102 || i == 98 || i == 69 || i == 70 || i == 66) && j < 53 && (locate(c, 'b', '0', 'f') == 1))
        {
            b[0] = i;

        }
        else if ((i == 97 || i == 100 || i == 99 || i == 65 || i == 68 || i == 67) && j < 53 && (locate(c, 'a', '2') == 1))
        {
            a[2] = i;

        }
        else
        {
            d[0] = i;
            locate(c, 'd', '0', 'f');
        }
    }
}


void even_func(char i, char j, char x, string& c, string& d, string& e, string& f)
{

    if ((i >= 53 && i <= 57) && (j >= 53 && j <= 57)) //5-9 | 5-9
    {
        if ((i > j) && (locate(d, 'f', '0') == 1))
        {
            f[0] = i;
        }
        else if ((i > j) && (locate(d, 'c', '3', 'b') == 1))
        {
            c[3] = i;
        }
        else if ((j > i) && (locate(d, 'f', '6') == 1))
        {
            f[6] = i;
        }
        else if ((j > i) && (locate(d, 'e', '5', 'a') == 1))
        {
            e[5] = i;
        }
        else if (i == j && (locate(d, 'f', '3', 'b') == 1))
        {
            f[3] = i;

        }
        else if (i == j && (locate(d, 'e', '1', 'd') == 1))
        {
            e[1] = i;

        }
        else if (i == j && (locate(d, 'c', '5', 'a') == 1))
        {
            c[5] = i;

        }
        else if (i == j && (locate(d, 'e', '4') == 1))
        {
            e[4] = i;

        }
        else if (i == j && (locate(d, 'f', '5', 'a') == 1))
        {
            f[5] = i;

        }
        else
        {
            e[0] = i;
            locate(d, 'e', '0');
        }
    }

    else if ((i >= 53 && i <= 57) && (j >= 48 && j <= 52)) //5-9 | 0-4
    {
        if ((i - j > 3) && (x >= 48 && x <= 57) && (locate(d, 'e', '2') == 1))
        {
            e[2] = i;
        }
        else if ((i - j > 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(d, 'c', '1', 'd') == 1))
        {
            c[1] = i;
        }
        else if ((i - j <= 3) && (x >= 48 && x <= 57) && (locate(d, 'e', '5', 'a') == 1))
        {
            e[5] = i;
        }
        else if ((i - j <= 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(d, 'f', '6') == 1))
        {
            f[6] = i;
        }
        else
        {
            c[6] = i;
            locate(d, 'c', '6');
        }
    }

    else if ((i >= 48 && i <= 52) && (j >= 53 && j <= 57)) //0-4 | 5-9
    {
        if ((j - i > 3) && (x >= 48 && x <= 57) && (locate(d, 'e', '1', 'd') == 1))
        {
            e[1] = i;

        }
        else if ((j - i > 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(d, 'c', '3', 'b') == 1))
        {
            c[3] = i;

        }
        else if ((j - i <= 3) && (x >= 48 && x <= 57) && (locate(d, 'c', '5', 'a') == 1))
        {
            c[5] = i;

        }
        else if ((j - i <= 3) && ((x >= 97 && x <= 102) || (x >= 65 && x <= 70)) && (locate(d, 'f', '0') == 1))
        {
            f[0] = i;

        }
        else
        {
            c[4] = i;
            locate(d, 'c', '4');
        }
    }

    else if ((i >= 48 && i <= 52) && (j >= 48 && j <= 52)) //0-4 | 0-4
    {
        if (i > j && (locate(d, 'f', '6') == 1))
        {
            f[6] = i;

        }
        else if (i > j && (locate(d, 'f', '5', 'a') == 1))
        {
            f[5] = i;

        }
        else if (j > i && (locate(d, 'e', '4') == 1))
        {
            e[4] = i;

        }
        else if (j > i && (locate(d, 'c', '3', 'b') == 1))
        {
            c[3] = i;

        }
        else if (i == j && (locate(d, 'e', '2') == 1))
        {
            e[2] = i;

        }
        else if (i == j && (locate(d, 'c', '1', 'd') == 1))
        {
            c[1] = i;

        }
        else if (i == j && (locate(d, 'f', '0') == 1))
        {
            f[0] = i;

        }
        else if (i == j && (locate(d, 'c', '5', 'a') == 1))
        {
            c[5] = i;

        }
        else if (i == j && (locate(d, 'e', '1', 'd') == 1))
        {
            e[1] = i;

        }
        else
        {
            e[3] = i;
            locate(d, 'e', '3', 'b');
        }
    }

    else if (((i >= 97 && i <= 102) || (i >= 65 && i <= 70)) && ((j >= 97 && j <= 102) || (j >= 65 && j <= 70))) //let | let
    {
        if (locate(d, 'e', '1', 'd') == 1)
        {
            e[1] = i;

        }
        else if (locate(d, 'f', '0') == 1)
        {
            f[0] = i;

        }
        else if (locate(d, 'c', '3', 'b') == 1)
        {
            c[3] = i;

        }
        else if (locate(d, 'e', '4') == 1)
        {
            e[4] = i;

        }
        else
        {
            f[1] = i;
            locate(d, 'f', '1', 'd');
        }
    }

    else if ((i >= 48 && i <= 57) && ((j >= 97 && j <= 102) || (j >= 65 && j <= 70))) // 0-9 | let
    {
        if (i >= 53 && (j == 101 || j == 102 || j == 98 || j == 69 || j == 70 || j == 66) && (locate(d, 'e', '4') == 1))
        {
            e[4] = i;

        }
        else if (i >= 53 && (j == 97 || j == 100 || j == 99 || j == 65 || j == 68 || j == 67) && (locate(d, 'f', '3', 'b') == 1))
        {
            f[3] = i;

        }
        else if (i < 53 && (j == 101 || j == 102 || j == 98 || j == 69 || j == 70 || j == 66) && (locate(d, 'c', '0') == 1))
        {
            c[0] = i;

        }
        else if (i < 53 && (j == 97 || j == 100 || j == 99 || j == 65 || j == 68 || j == 67) && (locate(d, 'c', '1', 'd') == 1))
        {
            c[1] = i;

        }
        else
        {
            c[7] = i;
            locate(d, 'c', '7');
        }
    }

    else if (((i >= 97 && i <= 102) || (i >= 65 && i <= 70)) && (j >= 48 && j <= 57)) // let | 0-9
    {
        if ((i == 101 || i == 102 || i == 98 || i == 69 || i == 70 || i == 66) && j >= 53 && (locate(d, 'c', '5', 'a') == 1))
        {
            c[5] = i;

        }
        else if ((i == 97 || i == 100 || i == 99 || i == 65 || i == 68 || i == 67) && j >= 53 && (locate(d, 'e', '1', 'd') == 1))
        {
            e[1] = i;

        }
        else if ((i == 101 || i == 102 || i == 98 || i == 69 || i == 70 || i == 66) && j < 53 && (locate(d, 'c', '3', 'b') == 1))
        {
            c[3] = i;
        }
        else if ((i == 97 || i == 100 || i == 99 || i == 65 || i == 68 || i == 67) && j < 53 && (locate(d, 'f', '0') == 1))
        {
            f[0] = i;

        }
        else
        {
            f[2] = i;
            locate(d, 'f', '2');
        }
    }
}