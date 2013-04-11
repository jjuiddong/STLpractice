/**
Name:   main.cpp
Author:  jjuiddong
Date:    4/10/2013

hash_map vs map

===========================
테스트 1
키 = 20개의 랜덤으로 만들어진 알파벳 스트링

데이타 갯수: 십만개
CAtlMap		 180.920 millisecond 
map				1812.640869 millisecond
hash_map	너무 오래걸려서 중간에 끔, 1분이상 걸림


===========================
테스트 2
키 = 랜덤으로 만들어진 int

데이타 갯수 	십만개
CAtlMap		 114.920 millisecond 
map				745.780 millisecond
hash_map	1171.985 millisecond


===========================
결론: 
키 값이  거의 중복이 되지 않으며, 데이타갯수가 많을 때, int, string 의 
키값으로 하는 경우는 log(N) 성능을 가진 map 이 더 빠르게 나왔다.

CAtlMap이 가장 좋은 결과를 내지만, std::string을 쓰는 방법을 몰라 
일단 보류 중이다. 

hash_map 은 해쉬함수를 어떻게 만드느냐에 따라 영향이 크기 때문에
전문적으로 이것을 연구하지 않는 이상 잘 만들기가 힘들다. 
기본으로 제공하는 해쉬함수를 쓸 경우 log(N)으로 검색하는 map보다
느리다. 

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

// a는 float type milli second이고 b가 FALSE일때는 에러입니다
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

	if(err) printf("printf() 걸린 시간은.. %8.6f미리세컨입니다.",Time);
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

	if(err) printf("printf() 걸린 시간은.. %8.6f미리세컨입니다.",Time);
}


void main()
{
	testSet1();
	//testSet2();
}

