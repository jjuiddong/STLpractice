// Unique.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	vector<int> lala;
	lala.push_back(1);
	lala.push_back(99);
	lala.push_back(3);
	lala.push_back(99);

	sort(lala.begin(), lala.end()); // lala: 1, 3, 99, 99
	lala.erase(unique(lala.begin(), lala.end()), lala.end()); // lala: 1, 3, 99

	auto it = lala.begin();
	while (lala.end() != it)
		printf("%d\n", *it++);
}
