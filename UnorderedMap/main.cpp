/**
Name:   main.cpp
Author:  jjuiddong
Date:    4/10/2013

hash_map vs map

===========================
�׽�Ʈ 1
Ű = 20���� �������� ������� ���ĺ� ��Ʈ��

����Ÿ ����: �ʸ���
CAtlMap		 180.920 millisecond 
map				1812.640869 millisecond
hash_map	�ʹ� �����ɷ��� �߰��� ��, 1���̻� �ɸ�


===========================
�׽�Ʈ 2
Ű = �������� ������� int

����Ÿ ���� 	�ʸ���
CAtlMap		 114.920 millisecond 
map				745.780 millisecond
hash_map	1171.985 millisecond


===========================
���: 
Ű ����  ���� �ߺ��� ���� ������, ����Ÿ������ ���� ��, int, string �� 
Ű������ �ϴ� ���� log(N) ������ ���� map �� �� ������ ���Դ�.

CAtlMap�� ���� ���� ����� ������, std::string�� ���� ����� ���� 
�ϴ� ���� ���̴�. 

hash_map �� �ؽ��Լ��� ��� ������Ŀ� ���� ������ ũ�� ������
���������� �̰��� �������� �ʴ� �̻� �� ����Ⱑ �����. 
�⺻���� �����ϴ� �ؽ��Լ��� �� ��� log(N)���� �˻��ϴ� map����
������. 

*/

#include <iostream>
#include <windows.h>
#include <hash_map>
#include <atlcoll.h>
#include <atlstr.h>
#include <map>
#include <algorithm>
using namespace std;
using namespace stdext;

#define CHECK_TIME_START __int64 freq, start, end; if (QueryPerformanceFrequency((_LARGE_INTEGER*)&freq)) {QueryPerformanceCounter((_LARGE_INTEGER*)&start);  

// a�� float type milli second�̰� b�� FALSE�϶��� �����Դϴ�
#define CHECK_TIME_END(a,b) QueryPerformanceCounter((_LARGE_INTEGER*)&end); a=(float)((double)(end - start)/freq*1000); b=TRUE; } else b=FALSE;

template <class T> struct myhash{};
template <> struct myhash<string>
{
	size_t operator()(string &to_hash) const
	{
		const char * in = to_hash.c_str();
		size_t out=0;
		while(NULL != *in)
		{
			out*= 53; //just a prime number
			out+= *in;
			++in;
		}
		return out;
	}
};

namespace std { 
	template<> struct less<string>
	{
		bool operator() (const string &s1, const string &s2) const
		{
			return (s1.compare(s2) < 0)? true : false;
		}
	};
}


string GenKey()
{
	string s;
	for (int i=0; i < 20; ++i)
	{
		s += ('A' + (rand()%('z'-'A')));
	}
	return s;
}

// key = string
void testSet1()
{
	const int TEST_SET = 100000;

	list<string> keys;
	for (int i=0; i < TEST_SET; ++i)
	{
		keys.push_back( GenKey() );
	}

	float Time;
	bool err;
	CHECK_TIME_START;

	//typedef hash_map<string, int > myMap;
	//typedef CAtlMap<CAtlString, int> myMap;
	//typedef CAtlMap<string, int> myMap;
	//typedef CAtlMap<const char*, int> myMap;
	typedef map<const char*, int > myMap;
	//typedef map<string, int > myMap;
	myMap m;
	auto it = keys.begin();
	while (keys.end() != it)
	{
		m[ it->c_str()]++;
		++it;
	}

	CHECK_TIME_END(Time, err);

	if(err) printf("printf() �ɸ� �ð���.. %8.6f�̸������Դϴ�.",Time);
}


// key = int
void testSet2()
{
	const int TEST_SET = 100000;

	list<int> keys;
	for (int i=0; i < TEST_SET; ++i)
	{
		keys.push_back( rand() );
	}

	float Time;
	bool err;
	CHECK_TIME_START;

	//typedef hash_map<int, int > myMap;
	typedef CAtlMap<int, int> myMap;
	//typedef map<int, int > myMap;
	myMap m;
	auto it = keys.begin();
	while (keys.end() != it)
	{
		m[ *it]++;
		++it;
	}

	CHECK_TIME_END(Time, err);

	if(err) printf("printf() �ɸ� �ð���.. %8.6f�̸������Դϴ�.",Time);
}


void main()
{
	testSet1();
	//testSet2();
}

