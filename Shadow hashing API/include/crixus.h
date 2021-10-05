#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include "sha256.h"
#include "SHA_256.h"
#include "functions.h"
#include "echo.h"
#include <future>
#include <mutex>

using namespace std;

//std::mutex printMutex;

void whiskey(string& str)
{
	auto i = begin(str);
	auto j = next(next(i));

	echo(str, *i, *j, 0);

	advance(j, 2);
	advance(i, 2);

	echo(str, *i, *j, 2);

	advance(j, 2);
	advance(i, 2);

	echo(str, *i, *j, 4);
}

void lima(string& str)
{
	auto i = begin(str);
	auto j = next(next(i));

	echo(str, *i, *j, 0);

	advance(j, 2);
	advance(i, 2);

	echo(str, *i, *j, 2);

	advance(j, 2);
	advance(i, 2);

	echo(str, *i, *j, 4);
}

void reserver(string& a, string& b, string& c, string& d, int n)
{
	a.reserve(n);
	b.reserve(n);
	c.reserve(n);
	d.reserve(n);
}

void zulu(string& s) //odd
{
	//if s.length < 32 !!
	auto pos = begin(s);
	auto poc = end(s);

	advance(pos, 16);
	advance(poc, -8);

	fill(pos, poc, '0');

}

void yankee(string& r)  //even
{
	auto pos = begin(r);
	auto poc = begin(r);

	advance(pos, 8);

	advance(poc, 16);

	fill(pos, poc, '0');

}

string oscar(string& f, string& k)  //for odd   f=32  k=8
{
	string a, b, c, d;

	reserver(a, b, c, d, 8);

	a = f.substr(0, 8);
	b = f.substr(8, 8);
	c = f.substr(16, 8);
	d = f.substr(24);

	char& r = a[5];
	r = k[4];

	char& s = b[2];
	s = k[5];

	char& t = d[3];
	t = k[6];

	char& u = b[7];
	u = k[7];

	auto i = begin(k);
	auto j = next(i);

	auto x = --end(k);

	//cout<<"i is "<<*i <<" j is "<<*j<<endl;
	odd_func(*i, *j, *x, a, b, c, d);

	iter_swap(i, j);
	//cout<<"i is "<<*i <<" j is "<<*j<<endl;
	odd_func(*i, *j, *x, a, b, c, d);

	advance(i, 2);
	advance(j, 2);

	//cout<<"i is "<<*i <<" j is "<<*j<<endl;

	odd_func(*i, *j, *x, a, b, c, d);

	iter_swap(i, j);
	//cout<<"i is "<<*i <<" j is "<<*j<<endl;

	odd_func(*i, *j, *x, a, b, c, d);

	whiskey(c);
	//cout<<"after whiskey "<<c<<endl;

	ofstream out;
	out.open("sha.txt", ios::app);

	out << c << endl;

	out.close();

	string&& ss = a + b + c + d;    	//ss is an lvalue

	return ss;
}

string delta(string& v, string& k) //for even
{
	string c, d, e, f;

	reserver(c, d, e, f, 8);

	c = v.substr(0, 8);
	d = v.substr(8, 8);
	e = v.substr(16, 8);
	f = v.substr(24);

	char& r = c[2];
	r = k[4];

	char& s = e[6];
	s = k[5];

	char& t = f[4];
	t = k[6];

	char& u = f[7];
	u = k[7];

	auto i = begin(k);
	auto j = next(i);

	auto x = --end(k);

	even_func(*i, *j, *x, c, d, e, f);

	iter_swap(i, j);
	//cout<<"i is "<<*i <<" j is "<<*j<<endl;
	even_func(*i, *j, *x, c, d, e, f);

	advance(i, 2);
	advance(j, 2);

	//cout<<"i is "<<*i <<" j is "<<*j<<endl;

	even_func(*i, *j, *x, c, d, e, f);

	iter_swap(i, j);
	//cout<<"i is "<<*i <<" j is "<<*j<<endl;

	even_func(*i, *j, *x, c, d, e, f);



	string&& ss = c + d + e + f;

	return ss;
}

/*counter(string& str, char c)
{
	int num = count(begin(str), end(str), c);
	{
		//cout<<"Number of "<<c<<"s : "<<num<<endl;
	}
}
*/
pair<string, string> crixus(string elem)
{

	string y = sha256(elem);


	string key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8;

	string x1, x2, x3, x4, x5, x6, x7, x8;

	string xx1, xx2, xx3, xx4, xx5, xx6, xx7, xx8;

	string finale;
	finale.reserve(257);

	//string y = elem;
	//cout<< "SYMMETRIC KEY "<<y<<endl<<endl;
	//string y = ("f427c7b3 8e7334d8 e5373f82 2279f427 c7b38e73 34d8e538 9cff167a 1dc30e73"); 

	key_1 = y.substr(0, 8);
	key_2 = y.substr(8, 8);
	key_3 = y.substr(16, 8);
	key_4 = y.substr(24, 8);
	key_5 = y.substr(32, 8);
	key_6 = y.substr(40, 8);
	key_7 = y.substr(48, 8);
	key_8 = y.substr(56, 8);
	//cout<<"key 8 "<<key_8<<endl;

  //template<typename T, typename ... Types>  refactor needed
  //reserver(x1, x2, x3, x4, 65);
  //reserver(x5, x6, x7, x8, 65);   not really needed

	x1 = sha256(key_1);
	x1 = x1.substr(32);
	x1.shrink_to_fit();

	x2 = sha256(key_2);
	x2 = x2.substr(32);
	x2.shrink_to_fit();

	x3 = sha256(key_3);
	x3 = x3.substr(32);
	x3.shrink_to_fit();

	x4 = sha256(key_4);
	x4 = x4.substr(32);
	x4.shrink_to_fit();

	x5 = sha256(key_5);
	x5 = x5.substr(32);
	x5.shrink_to_fit();

	x6 = sha256(key_6);
	x6 = x6.substr(32);
	x6.shrink_to_fit();

	x7 = sha256(key_7);
	x7 = x7.substr(32);
	x7.shrink_to_fit();

	x8 = sha256(key_8);
	x8 = x8.substr(32);
	x8.shrink_to_fit();

	//zulu and yankee are for the zeros   
	//NEED CONCURRENCY

	zulu(x1); //cout<<"x1 "<<x1<<endl;

	yankee(x2);	//cout<<"x2 "<<x2<<endl; 

	zulu(x3);	//cout<<"x3 "<<x3<<endl;

	yankee(x4);	//cout<<"x4 "<<x4<<endl;

	zulu(x5);	//cout<<"x5 "<<x5<<endl;

	yankee(x6);	//cout<<"x6 "<<x6<<endl;

	zulu(x7);	//cout<<"x7 "<<x7<<endl;

	yankee(x8);	//cout<<"x8 "<<x8<<endl<<endl;


	xx1 = oscar(x1, key_1);  //cout<<"xx1 "<<xx1<<endl;

	xx2 = delta(x2, key_2);	 //cout<<"xx2 "<<xx2<<endl;

	xx3 = oscar(x3, key_3);	//cout<<"xx3 "<<xx3<<endl;

	xx4 = delta(x4, key_4);	//cout<<"xx4 "<<xx4<<endl;

	xx5 = oscar(x5, key_5);	//cout<<"xx5 "<<xx5<<endl;

	xx6 = delta(x6, key_6);	//cout<<"xx6 "<<xx6<<endl;

	xx7 = oscar(x7, key_7);	//cout<<"xx7 "<<xx7<<endl;

	xx8 = delta(x8, key_8);	//cout<<"xx8 "<<xx8<<endl<<endl;


	finale = xx1 + xx2 + xx3 + xx4 + xx5 + xx6 + xx7 + xx8;

	transform(begin(finale), end(finale), // source
		begin(finale), // destination
		[](char c) { // operation
			return toupper(c);
		});

	//shuffle
	auto q = begin(finale);
	auto w = next(q);
	advance(w, 10);

	reverse(q, w);

	auto n = end(finale);
	auto m = prev(n);
	advance(m, -10);

	reverse(m, n);

	/*counter(finale, '0');
	counter(finale, '1');
	counter(finale, '2');
	counter(finale, '3');
	counter(finale, '4');
	counter(finale, '5');
	counter(finale, '6');
	counter(finale, '7');
	counter(finale, '8');
	counter(finale, '9');
	counter(finale, 'A');
	counter(finale, 'B');
	counter(finale, 'C');
	counter(finale, 'D');
	counter(finale, 'E');
	counter(finale, 'F');
	*/
	//cout<<endl<<endl<<endl;

	return make_pair(y, finale);

	// empty any reamining containers

}

string crixus_2(string elem)
{

	string y = elem;


	string key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8;

	string x1, x2, x3, x4, x5, x6, x7, x8;

	string xx1, xx2, xx3, xx4, xx5, xx6, xx7, xx8;

	string finale;
	finale.reserve(257);

	//string y = elem;
	//cout<< "SYMMETRIC KEY "<<y<<endl<<endl;
	//string y = ("f427c7b3 8e7334d8 e5373f82 2279f427 c7b38e73 34d8e538 9cff167a 1dc30e73"); 

	key_1 = y.substr(0, 8);
	key_2 = y.substr(8, 8);
	key_3 = y.substr(16, 8);
	key_4 = y.substr(24, 8);
	key_5 = y.substr(32, 8);
	key_6 = y.substr(40, 8);
	key_7 = y.substr(48, 8);
	key_8 = y.substr(56, 8);
	//cout<<"key 8 "<<key_8<<endl;

  //template<typename T, typename ... Types>  refactor needed
  //reserver(x1, x2, x3, x4, 65);
  //reserver(x5, x6, x7, x8, 65);   not really needed

	x1 = sha256(move(key_1));
	x1 = x1.substr(32);
	x1.shrink_to_fit();

	x2 = sha256(key_2);
	x2 = x2.substr(32);
	x2.shrink_to_fit();

	x3 = sha256(key_3);
	x3 = x3.substr(32);
	x3.shrink_to_fit();

	x4 = sha256(key_4);
	x4 = x4.substr(32);
	x4.shrink_to_fit();

	x5 = sha256(key_5);
	x5 = x5.substr(32);
	x5.shrink_to_fit();

	x6 = sha256(key_6);
	x6 = x6.substr(32);
	x6.shrink_to_fit();

	x7 = sha256(key_7);
	x7 = x7.substr(32);
	x7.shrink_to_fit();

	x8 = sha256(key_8);
	x8 = x8.substr(32);
	x8.shrink_to_fit();

	//zulu and yankee are for the zeros   
	//NEED CONCURRENCY

	zulu(x1); //cout<<"x1 "<<x1<<endl;

	yankee(x2);	//cout<<"x2 "<<x2<<endl; 

	zulu(x3);	//cout<<"x3 "<<x3<<endl;

	yankee(x4);	//cout<<"x4 "<<x4<<endl;

	zulu(x5);	//cout<<"x5 "<<x5<<endl;

	yankee(x6);	//cout<<"x6 "<<x6<<endl;

	zulu(x7);	//cout<<"x7 "<<x7<<endl;

	yankee(x8);	//cout<<"x8 "<<x8<<endl<<endl;


	xx1 = oscar(x1, key_1);  //cout<<"xx1 "<<xx1<<endl;

	xx2 = delta(x2, key_2);	 //cout<<"xx2 "<<xx2<<endl;

	xx3 = oscar(x3, key_3);	//cout<<"xx3 "<<xx3<<endl;

	xx4 = delta(x4, key_4);	//cout<<"xx4 "<<xx4<<endl;

	xx5 = oscar(x5, key_5);	//cout<<"xx5 "<<xx5<<endl;

	xx6 = delta(x6, key_6);	//cout<<"xx6 "<<xx6<<endl;

	xx7 = oscar(x7, key_7);	//cout<<"xx7 "<<xx7<<endl;

	xx8 = delta(x8, key_8);	//cout<<"xx8 "<<xx8<<endl<<endl;


	finale = xx1 + xx2 + xx3 + xx4 + xx5 + xx6 + xx7 + xx8;

	transform(begin(finale), end(finale), // source
		begin(finale), // destination
		[](char c) { // operation
			return toupper(c);
		});

	//shuffle
	auto q = begin(finale);
	auto w = next(q);
	advance(w, 10);

	reverse(q, w);

	auto n = end(finale);
	auto m = prev(n);
	advance(m, -10);

	reverse(m, n);


	return finale;

	// empty any reamining containers

}

