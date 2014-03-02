// Unique.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
