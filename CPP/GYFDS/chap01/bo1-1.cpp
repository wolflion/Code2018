#include "c1.h"
#include "c1-1.h"

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	// 操作结果：构造三元组T，依次置T的三个元素的初值为v1,v2和v3
	if (!(T = (ElemType *)malloc(3*sizeof(ElemType))))
	{
		exit(OVERFLOW);
	}
	T[0] = v1, T[1] = v2, T[2] = v3;
	return OK;
}

Status DestroyTriplet(Triplet &T)
{
	// 操作结果：三元组T被销毁
	free(T);
	T = NULL;
	return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
	// 初始条件：三元组T已存在，1<=i<=3。
	// 操作结果：用e返回T的第i元的值
	if (i<1 || i>3)
	{
		return ERROR;
	}
	e = T[i - 1];
	return OK;
}