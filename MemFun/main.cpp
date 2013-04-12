
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <boost/bind.hpp>

using namespace std;

class Record
{
public:
	Record() {}
	Record(const string &n) : m_name(n) {}
	string m_name;
};

bool name_key_eq(const Record &r, const string &name)
{
	return r.m_name == name;
}

void main()
{	
	typedef list<Record> RecordList;
	RecordList lr;
	lr.push_back( Record("abb") );
	lr.push_back( Record("bbc") );
	lr.push_back( Record("ddde") );
	lr.push_back( Record("ffffa") );

	//auto it = find_if( lr.begin(), lr.end(), bind2nd(ptr_fun(name_key_eq), "ddde") );
	auto it = find_if( lr.begin(), lr.end(), boost::bind(name_key_eq, _1, "ddde") );
	if (lr.end() != it)
		cout << it->m_name;

}
