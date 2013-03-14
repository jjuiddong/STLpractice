
#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>

using namespace boost;

class CA
{
public:
	CA(const std::string &str) : m_Str(str) {}
	CA(const CA&rhs) : m_Str(rhs.m_Str) {}

	const std::string& GetName() const { return m_Str; }

	void Display()
	{
		std::cout << "Display " << m_Str << std::endl;
	}

	void Display2(int n)
	{
		std::cout << "Display " << m_Str << n << std::endl;
	}

	bool operator==(const CA& rhs)
	{
		return m_Str == rhs.m_Str;
	}

protected:
	std::string m_Str;
};

template<class T>
bool IsSameName(const T &t, const std::string &name) {
	return t->GetName() == name;
}
template<class T>
bool IsSameName2(const T &t, const std::string &name) {
	return t.GetName() == name;
}
bool IsSameName3(CA &t, int n) {
	return t.GetName() == "aa";
}
bool IsSameName4(const CA &t, const std::string &name) {
	return t.GetName() == name;
}

template<class T>
bool IsSameValue(const T &tx, const T &ty)
{
	return tx == ty;
}

void DispA( CA &a ) {
	a.Display();
}
void Disp2A( CA &a, int n ) {
	a.Display2(n);
}


int  main()
{
	std::list<CA*> AList;
	AList.push_back( new CA("aa") );
	AList.push_back( new CA("bb") );
	AList.push_back( new CA("cc") );
	AList.push_back( new CA("dd") );

	std::cout << std::endl;
	auto it1 = std::find_if(AList.begin(), AList.end(), 
		boost::bind(&IsSameName<CA*>, _1, "cc") );
	if (AList.end() != it1)
		(*it1)->Display();

	auto it2 = std::find_if(AList.begin(), AList.end(), 
		boost::bind(&IsSameValue<std::string>, 
			boost::bind(&CA::GetName, _1), "aa") );
	if (AList.end() != it2)
		(*it2)->Display();

	//bool bb = IsSameValue(std::string("aaa"), std::string("aaa"));

	std::list<CA> AObjList;
	AObjList.push_back( CA("aa") );
	AObjList.push_back( CA("bb") );
	AObjList.push_back( CA("cc") );
	AObjList.push_back( CA("dd") );

	std::cout << std::endl;
	auto it = std::find_if(AObjList.begin(), AObjList.end(), 
		boost::bind(&IsSameName2<CA>, _1, "dd") );
	if (AObjList.end() != it)
		it->Display();

	std::cout << std::endl;
	std::for_each(AObjList.begin(), AObjList.end(), 
		boost::bind(&DispA, _1) );

	std::cout << std::endl;
	std::for_each(AObjList.begin(), AObjList.end(), 
		boost::bind(&Disp2A, _1, 10) );

	std::cout << std::endl;
	std::for_each(AObjList.begin(), AObjList.end(), 
		boost::bind(&CA::Display, _1) );

	std::cout << std::endl;
	BOOST_FOREACH(auto &obj, AObjList)
	{
		obj.Display();
	}

	//auto it = std::find_if(AList.begin(), AList.end(), 
	//	bind(IsSameName, _1, "aa") );	

	//boost::bind<CA*>(IsSameName, _1, _2)(&CA("aa"), "aa");
	

	return 0;
}
