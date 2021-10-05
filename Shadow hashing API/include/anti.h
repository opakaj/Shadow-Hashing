#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <un_echo.h>

using namespace std;


string even_shadow(string& k)
{
	string c, d, e, f;
	string s = "00000000";

	//reserver(e,f,c,d,8);

	c = k.substr(0, 8);
	d = k.substr(8, 8);
	e = k.substr(16, 8);
	f = k.substr(24);

	char& r = s[4];
	r = c[2];

	char& t = s[5];
	t = e[6];

	char& u = s[6];
	u = f[4];

	char& v = s[7];
	v = f[7];

	auto i2 = begin(d);
	auto i3 = next(i2);
	int n = 0;

	while (i2 < prev(end(d)) && i3 < end(d) && n < 4)
	{
		if (*i2 == 'c')
		{
			if (*i3 == '0') s[n] = c[0]; 		//fixed

			else if (*i3 == '2') s[n] = c[2];

			else if (*i3 == '4') s[n] = c[4];

			else if (*i3 == '6') s[n] = c[6];

			else if (*i3 == 'd') s[n] = c[1];

			else if (*i3 == 'b') s[n] = c[3];

			else if (*i3 == 'a') s[n] = c[5];

			else if (*i3 == '7') s[n] = c[7];
		}

		else if (*i2 == 'e')
		{
			if (*i3 == '0') s[n] = e[0]; 		//fixed

			else if (*i3 == '2') s[n] = e[2];

			else if (*i3 == '4') s[n] = e[4];

			else if (*i3 == '6') s[n] = e[6];

			else if (*i3 == 'd') s[n] = e[1];

			else if (*i3 == 'b') s[n] = e[3];

			else if (*i3 == 'a') s[n] = e[5];

			else if (*i3 == '7') s[n] = e[7];
		}

		else if (*i2 == 'f')
		{
			if (*i3 == '0') s[n] = f[0]; 		//fixed

			else if (*i3 == '2') s[n] = f[2];

			else if (*i3 == '4') s[n] = f[4];

			else if (*i3 == '6') s[n] = f[6];

			else if (*i3 == 'd') s[n] = f[1];

			else if (*i3 == 'b') s[n] = f[3];

			else if (*i3 == 'a') s[n] = f[5];

			else if (*i3 == '7') s[n] = f[7];
		}

		else
			break;

		advance(i2, 2);
		advance(i3, 2);
		n += 1;
	}

	return s;
}

string odd_shadow(string& f)
{
	string a, b, c, d;
	string s = "00000000";

	//reserver(a,b,c,d,8);

	a = f.substr(0, 8);
	b = f.substr(8, 8);
	c = f.substr(16, 8);
	d = f.substr(24);

	un_echo(c);

	char& r = s[4];
	r = a[5];

	char& t = s[5];
	t = b[2];

	char& u = s[6];
	u = d[3];

	char& v = s[7];
	v = b[7];

	auto i2 = begin(c);
	auto i3 = next(i2);
	int n = 0;

	while (i2 < prev(end(c)) && i3 < end(c) && n < 4)
	{
		if (*i2 == 'a')
		{
			if (*i3 == '2') s[n] = a[2]; 		//fixed

			else if (*i3 == '5') s[n] = a[5];

			else if (*i3 == '6') s[n] = a[6];

			else if (*i3 == '7') s[n] = a[7];

			else if (*i3 == 'f') s[n] = a[0];

			else if (*i3 == 'e') s[n] = a[1];

			else if (*i3 == 'a') s[n] = a[3];

			else if (*i3 == 'c') s[n] = a[4];
		}

		else if (*i2 == 'b')
		{
			if (*i3 == '2') s[n] = b[2]; 		//fixed

			else if (*i3 == '5') s[n] = b[5];

			else if (*i3 == '6') s[n] = b[6];

			else if (*i3 == '7') s[n] = b[7];

			else if (*i3 == 'f') s[n] = b[0];

			else if (*i3 == 'e') s[n] = b[1];

			else if (*i3 == 'a') s[n] = b[3];

			else if (*i3 == 'c') s[n] = b[4];
		}

		else if (*i2 == 'd')
		{
			if (*i3 == '2') s[n] = d[2]; 		//fixed

			else if (*i3 == '5') s[n] = d[5];

			else if (*i3 == '6') s[n] = d[6];

			else if (*i3 == '7') s[n] = d[7];

			else if (*i3 == 'f') s[n] = d[0];

			else if (*i3 == 'e') s[n] = d[1];

			else if (*i3 == 'a') s[n] = d[3];

			else if (*i3 == 'c') s[n] = d[4];
		}

		else
			break;

		advance(i2, 2);
		advance(i3, 2);
		n += 1;
	}


	return s;
}

string un_shadow(string& str)
{
	transform(begin(str), end(str), // source
		begin(str), // destination
		[](char c) { // operation
			return tolower(c);
		});

	auto q = begin(str);
	auto w = next(q);
	advance(w, 10);

	reverse(q, w);

	auto n = end(str);
	auto m = prev(n);
	advance(m, -10);

	reverse(m, n);

	string key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8;
	string x1, x2, x3, x4, x5, x6, x7, x8;

	key_1 = str.substr(0, 32);
	key_2 = str.substr(32, 32);
	key_3 = str.substr(64, 32);
	key_4 = str.substr(96, 32);
	key_5 = str.substr(128, 32);
	key_6 = str.substr(160, 32);
	key_7 = str.substr(192, 32);
	key_8 = str.substr(224);

	x1 = odd_shadow(key_1);
	x2 = even_shadow(key_2);
	x3 = odd_shadow(key_3);
	x4 = even_shadow(key_4);
	x5 = odd_shadow(key_5);
	x6 = even_shadow(key_6);
	x7 = odd_shadow(key_7);
	x8 = even_shadow(key_8);

	string sha256 = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;

	return sha256;
	//cout<<sha256<<endl;	
	//cout<<sha256.length()<<endl;
}

