#include "c1.h"
#include "c2-1.h"

Status InitList(SqList &L) // �㷨2.3  [�洢�ṹ��c2-1.h����]
{
	// �������������һ���յ�˳�����Ա�
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType);
	if (!L.elem)
	{
		exit(OVERFLOW); // �洢����ʧ�ܣ�OVERFLOW "math.h"���
	}
	L.length = 0;  // �ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE; // ��ʼ�洢����
	//return OK;
	return 1;
}

Status DestroyList(SqList &L)
{
	// ��ʼ������˳�����Ա�L�Ѵ��ڡ�
	// �������������˳�����Ա�L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

Status ClearList(SqList &L)
{
	// ��ʼ����:˳�����Ա�L�Ѵ���.
	// �������:��L����Ϊ�ձ�
	L.length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	// ��ʼ������˳�����Ա�L�Ѵ���
	// �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if (L.length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int ListLenth(SqList L)
{
	// ��ʼ������˳�����Ա�L�Ѵ���
	// �������������L������Ԫ�ظ���
	return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
	// ��ʼ������˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
	// �����������e����L�е�i������Ԫ�ص�ֵ
	if (i<1 || i>L.length)
	{
		exit(ERROR);
	}
	e = *(L.elem + i - 1);
	return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	// ��ʼ������˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
	// �����������e����L�е�i������Ԫ�ص�ֵ
	ElemType *p;
	int i = 1;
	p = L.elem;
	while (i<L.length && !compare(*p++,e))
	{
		++i;
	}
	if (i <= L.length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	// ��ʼ������˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
	// �����������e����L�е�i������Ԫ�ص�ֵ
	int i = 2;
	ElemType *p = L.elem + 1;
	while (i<=L.length&&*p!=cur_e)
	{
		p++;
		i++;
	}
	if (i>L.length)
	{
		return INFEASIBLE;
	}
	else
	{
		pre_e - *--p;
		return OK;
	}
}

Stutus NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	// ��ʼ������˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
	// �����������e����L�е�i������Ԫ�ص�ֵ
	int i = 1;
	ElemType *p = L.elem;
	while (i<L.length && *p!=cur_e)
	{
		i++;
		p++;
	}
	if (i==L.length)
	{
		return INFEASIBLE;
	}
	else
	{
		next_e = *++p;
		return OK;
	}
}

Stutus ListInsert(SqList &L, int i, ElemType e)
{
	// ��ʼ������˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)
	// �����������e����L�е�i������Ԫ�ص�ֵ
	ElemType *newbase, *q, *p;
	if (i<1||i>L.length+1)
	{
		return ERROR;
	}
	if (L.length >= L.listsize)  // ��ǰ�洢�ռ����������ӷ���
	{
		if (!(newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType))))
		{
			exit(OVERFLOW); // �洢����ʧ��
		}
		L.elem = newbase; // �»�ַ
		L.listsize += LISTINCREMENT; // ���Ӵ洢����
	}
	q = L.elem + i - 1;  // qΪ����λ��
	for (p = L.elem + L.length - 1; p >=q;--p) // ����λ�ü�֮���Ԫ������
	{
		*(p + 1) = *p;
	}
	*q = e; // ����e
	++L.length;  // ����1
	return OK;
}

// 22-450����99-450����2�²Ž���