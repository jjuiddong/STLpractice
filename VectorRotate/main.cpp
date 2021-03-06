
#include <iostream>
#include <vector>
using namespace std;


// ty 유니크할 때만 제대로 동작하는 함수다.
template <class Seq>
bool removevector(Seq &seq, const typename Seq::value_type &ty)
{
	for (size_t i=0; i < seq.size(); ++i)
	{
		if (seq[ i] == ty)
		{
			if ((seq.size()-1) > i) // elements를 회전해서 제거한다.
				std::rotate( seq.begin()+i, seq.begin()+i+1, seq.end() );

			// 제거될 때, pop을 호출하지 않는다. 이렇게 된다면, 데이타가 
			// 계속 쌓이고, 제거될 경우 메모리가 해제되지 않기 때문에, 
			// 메모리가 소모가 많을 수 있다. 주의할 것
			return true;
		}
	}
	return false;
}

template <class T>
void putvector( std::vector<T> &seq, size_t putIdx, const T &ty)
{
	if (seq.size() > putIdx)
		seq[ putIdx] = ty;
	else
		seq.push_back(ty);
}

// void inservector(const std::vector<T> &seq, u_int idx, const T &ty);


template<class T>
class sizevector : public std::vector<T>
{
public:
	sizevector() : m_Size(0) {}
	sizevector(size_t s) : vector<T>(s), m_Size(0) {}

	bool remove(const T &ty) {
		const bool r = removevector(*this, ty);
		if (r) --m_Size;
		return r;
	}
	void putback(const T &ty) {
		putvector(*this, m_Size, ty);
		++m_Size;
	}
	void popback() {
		--m_Size;
	}
	void clear() {
		std::vector<T>::clear();
		m_Size = 0;
	}
	size_t m_Size;

};

template<class T>
class nullvector : public std::vector<T>
{
public:
	nullvector() {}
	nullvector(size_t s) : vector<T>(s) {}

	void removevector(const T &ty) {
		removevector(*this, ty);
	}
	//void putvector(
	//size_t m_Size;
};



int main()
{
	vector<int> v(10);

	v[ 0] = 1;
	v[ 1] = 2;
	v[ 2] = 3;
	v.push_back( 10 );

	const int size = v.size();

	nullvector<int> vv(10);
	sizevector<int> vvs(10);

	vvs.putback(10);
	vvs.putback(11);
	vvs.putback(12);
	vvs.putback(13);
	vvs.putback(14);

	vvs.remove( 11 );
	vvs.remove( 14 );
	vvs.remove( 13 );
	vvs.putback( 9 );

	vvs.clear();

	//vector<int>::value


	return 0;
}
