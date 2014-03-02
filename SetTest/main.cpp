
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	set<int> test;

	test.insert( 1 );
	test.insert( 2 );
	test.insert( 3 );
	test.insert( 1 );

	copy(test.begin(), test.end(), ostream_iterator<int>(cout, "\n") );

	return 0;
}
