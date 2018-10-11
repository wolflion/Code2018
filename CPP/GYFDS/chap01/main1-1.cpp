// main1-1.cpp 检验基本操作bo1-1.cpp的主函数
#include "c1.h"
typedef int ElemType;
//typedef double ElemType;
#include "c1-1.h"
//#include "bo1-1.cpp"   // 这种写法会报错的吧，重新在c1-1.h里声明了一下bo1-1.cpp里实现的
using namespace std;

void main()
{
	Triplet T;
	ElemType m;
	Status i;
	i = InitTriplet(T,5,7,9);
	printf("调用初始化函数后，i=%d(1:成功)T的3个值为：",i);
	cout <<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;   // 为避免ElemType的类型变化的影响，用cout取代printf()。注意结尾要加endl
	i = Get(T,2,m);  // 将三元组T的第2个值赋给m
	if(i == OK)
		cout<<"T的第2个值为："<<m<<endl;
	i = Put(T,2,6);   // 将三元组T的第2个值改为6
	if(i==OK) // 调用Put()成功
		cout<<"将T的第2个值改为6后，T的3个值为："<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
	i=IsAscending(T); // 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变
	printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
	i=IsDescending(T);
	printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
	if((i=Max(T,m))==OK) // 先赋值再比较
		cout<<"T中的最大值为："<<m<<endl;
	if((i=Min(T,m))==OK)
		cout<<"T中的最小值为："<<m<<endl;
	DestroyTriplet(T); // 函数也可以不带回返回值
	cout<<"销毁T后，T="<<T<<"(NULL)"<<endl;
}
