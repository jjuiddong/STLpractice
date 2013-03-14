
#include <boost/bind.hpp>
#include <iostream>
#include <string>

template<class T>
bool IsSameValue(const T &tx, const T &ty)
{
	return tx == ty;
}

class CA
{
public:
	int m_i;
	char m_c;
	std::string m_str;

	int GetI() const {return m_i; }
	char GetC() const { return m_c; }
	const std::string& GetStr() const { return m_str; }
};

template<class T>
bool traverse(const CA *p, T &ty)
{
	if (ty(p))
		return true;
	return false;
}

int main()
{
	CA a;
	a.m_i = 10;
	a.m_str = "aa";

	bool b = traverse( &a,
		boost::bind(&IsSameValue<int>,
			boost::bind(&CA::GetI, _1), 10) );

	std::cout << b << std::endl;

	b = traverse( &a,
		boost::bind(&IsSameValue<std::string>,
			boost::bind(&CA::GetStr, _1), "aa") );
	std::cout << b << std::endl;

	b = traverse( &a,
		boost::bind(&IsSameValue<std::string>,
			boost::bind(&CA::GetStr, _1), "bb") );
	std::cout << b << std::endl;

	return 0;
}
