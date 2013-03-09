
#include <boost/bind.hpp>
#include <iostream>


int f(int a, int b)
{
	int c = a + b;
	std::cout << c << std::endl;
	return c;
}

int main()
{
	int a1 = 10, a2 = 20;
	boost::bind(f, _1, _2)(a1, a2);					// f(a1, a2)
	boost::bind(f, 10, _2)(a1, a2);					// f(10, a2)
	boost::bind(f, _1, 20)(a1, a2);					// f(a1, 20)
	boost::bind(f, _2, _1)(a1, a2);					// f(a2, a1)
	return 0;
}