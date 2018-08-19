#include "c1.h"
#include "c1-1.h"

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	// ���������������Ԫ��T��������T������Ԫ�صĳ�ֵΪv1,v2��v3
	if (!(T = (ElemType *)malloc(3*sizeof(ElemType))))
	{
		exit(OVERFLOW);
	}
	T[0] = v1, T[1] = v2, T[2] = v3;
	return OK;
}

Status DestroyTriplet(Triplet &T)
{
	// �����������Ԫ��T������
	free(T);
	T = NULL;
	return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
	// ��ʼ��������Ԫ��T�Ѵ��ڣ�1<=i<=3��
	// �����������e����T�ĵ�iԪ��ֵ
	if (i<1 || i>3)
	{
		return ERROR;
	}
	e = T[i - 1];
	return OK;
}