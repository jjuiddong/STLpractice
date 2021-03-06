// vector::reserve
#include <iostream>
#include <vector>

int main ()
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			int size = foo.size();
			std::cout << "capacity changed: " << sz << " size: " << size << '\n';
		}
	}

	std::cout << "delete foo \n";
	for (int i=0; i < 100; ++i)
	{
		foo.pop_back();
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			int size = foo.size();
			std::cout << "capacity changed: " << sz << " size: " << size << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}