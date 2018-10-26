//f1401.cpp 定义和使用函数模板
#include <iostream>
using namespace std;
template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	double dx = 3.5,dy = 5.6;
	int ix = 6,iy=7,ia=303,ib=505;
	string s1 = "good",s2="better";

	cout<<"double dx="<<dx<<", dy="<<dy<<"\n";
	cout<<"int ix="<<ix<<", iy="<<iy<<"\n";
	cout<<"string s1="<<s1<<", s2="<<s2<<"\n";

	swap(dx,dy);
	swap(ix,iy);
	swap(s1,s2);
	swap(ia,ib);

	cout << "\nafter swap:\n";
	cout<<"double dx="<<dx<<", dy="<<dy<<"\n";
	cout<<"int ix="<<ix<<", iy="<<iy<<"\n";
	cout<<"string s1="<<s1<<", s2="<<s2<<"\n";
}