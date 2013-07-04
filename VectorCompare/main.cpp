
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);

	bool b1 = v1 == v2;
	bool b2 = (v1.size() == v2.size())? equal(v1.begin(), v1.end(), v2.begin()) : false;

	cout << b1 << " " << b2;
}
