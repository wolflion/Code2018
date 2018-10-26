//f1405.cpp 模板重载
#include <iostream>
template <typename T>
T const& max(T const& a, T const& b)
{
	return a<b?b:a;
}

template<typename T>
T *const& max(T* const& 工， T* const& b)
{
	return *a<*b?b:a;
}

const char* const& max(const char* const& a, const char* const& b)
{
	return std::strcmp(a,b)<0?b:a;
}

int main()
{
	int ia=3,ib=7;
	char* s1="hello";
	char* s2= "hell";
	std::cout<<*max(&ia,&ib)<<"\n";    // 匹配于第二个模板
	std::cout<<max(s1,s2)<<"\n";  // 匹配于max函数
	std::cout<<max(ia,ib)<<"\n";   // 匹配于第一个模板
}


//g++ f1405.cpp