//f1403.cpp 用显式cast做模板类型匹配

#include <iostream>
template <typename T>
T const& max(T const& a, T const& b) // 常量引用型类型
{
	return a<b?b:a;
}

int main()
{
	int ia =3 ;
	double db = 5.0;
	std::cout<<max<double>(ia,db)<<"\n";
	std::cout<<max(static_cast<double>(ia),db)<<"\n";
}