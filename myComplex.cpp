#include<iostream>
using namespace std;

template<class T1,class T2>
class myComplex
{
public:
	myComplex() = default;
	~myComplex() = default;
	myComplex(const T1& x=0, const T2& y=0) :mX(x), mY(y) {};

	template<class T1, class T2>
	friend myComplex<T1, T2> operator+(const myComplex<T1, T2> c1, const myComplex<T1, T2>& c2);
	
	template<class T1, class T2>
	friend myComplex<T1, T2> operator-(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2);
	
	template<class T1, class T2>
	friend myComplex<T1, T2> operator*(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2);
	
	template<class T1, class T2>
	friend myComplex<T1, T2> operator/(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2);
	void show();

private:
	T1 mX;
	T2 mY;
};

//(a+bi)+(c+di)=(a+c)+(b+d)i
template<class T1,class T2>
myComplex<T1,T2> operator+(const myComplex<T1, T2> c1, const myComplex<T1, T2>& c2)
{
	return myComplex<T1, T2>(c1.mX + c2.mX, c1.mY + c2.mY);
}

template<class T1, class T2>
//(a+bi)-(c+di)=(a-c)+(b-d)i
myComplex<T1, T2> operator-(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2)
{
	return myComplex<T1, T2>(c1.mX - c2.mX, c1.mY - c2.mY);
}

template<class T1, class T2>
//(a+bi)*(c+di)=(ac-bd)+(bc+ad)i
myComplex<T1, T2> operator*(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2)
{
	return myComplex<T1, T2>(c1.mX * c2.mX - c1.mY * c2.mY, c1.mY * c2.mX + c1.mX * c2.mY);
}

template<class T1, class T2>
//(a+bi)/(c+di)=(ac+bd)/(c2+d2)+(bc-ad)/ (c2+d2)i
myComplex<T1, T2> operator/(const myComplex<T1, T2>& c1, const myComplex<T1, T2>& c2)
{
	return myComplex<T1,T2>((c1.mX * c2.mX + c1.mY * c2.mY) / (pow(c2.mX, 2) + pow(c2.mY, 2)), (c1.mY * c2.mX - c1.mX * c2.mY) / (pow(c2.mX, 2) + pow(c2.mY, 2)));
}

template<class T1, class T2>
inline void 
myComplex<T1, T2>::show()
{
	cout <<"mX:"<< mX << " mY:" << mY<<endl;
}


int main()
{
	//暂不考虑减负数之类的情况,换言之,输入数据保证双目运算的两个参数都是正数
	myComplex<int, int>c1(1, 2);
	myComplex<int, int>c2(-2, 4), c3(5, 5);
	myComplex<int,int> c4 = c1 + c2;
	c4.show();
	c4 = c1 - c2;
	c4.show();
	c4 = c1 * c3;
	c4.show();
	c4 = c3 / c2;
	c4.show();
	
}