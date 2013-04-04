
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	list<int> b;
	b.push_back(10);
	b.push_back(11);
	b.push_back(12);
	b.push_back(13);

	list<int> c;
	copy(a.begin(), a.end(), back_inserter(c) );
	copy(b.begin(), b.end(), back_inserter(c) );


	return 0;
}
