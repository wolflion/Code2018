#include "c1.h"
#include "c2-1.h"

Status InitList(SqList &L) // 算法2.3  [存储结构由c2-1.h定义]
{
	// 操作结果：构造一个空的顺序线性表
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType);
	if (!L.elem)
	{
		exit(OVERFLOW); // 存储分配失败；OVERFLOW "math.h"里的
	}
	L.length = 0;  // 空表长度为0
	L.listsize = LIST_INIT_SIZE; // 初始存储容量
	//return OK;
	return 1;
}

Status DestroyList(SqList &L)
{
	// 初始条件：顺序线性表L已存在。
	// 操作结果：销毁顺序线性表L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

Status ClearList(SqList &L)
{
	// 初始条件:顺序线性表L已存在.
	// 操作结果:将L重置为空表
	L.length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	// 初始条件：顺序线性表L已存在
	// 操作结果：若L为空表，则返回TRUE，否则返回FALSE
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
	// 初始条件：顺序线性表L已存在
	// 操作结果：返回L中数据元素个数
	return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
	// 初始条件：顺序线性表L已存在,1<=i<=ListLength(L)
	// 操作结果：用e返回L中第i个数据元素的值
	if (i<1 || i>L.length)
	{
		exit(ERROR);
	}
	e = *(L.elem + i - 1);
	return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	// 初始条件：顺序线性表L已存在,1<=i<=ListLength(L)
	// 操作结果：用e返回L中第i个数据元素的值
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
	// 初始条件：顺序线性表L已存在,1<=i<=ListLength(L)
	// 操作结果：用e返回L中第i个数据元素的值
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
	// 初始条件：顺序线性表L已存在,1<=i<=ListLength(L)
	// 操作结果：用e返回L中第i个数据元素的值
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
	// 初始条件：顺序线性表L已存在,1<=i<=ListLength(L)
	// 操作结果：用e返回L中第i个数据元素的值
	ElemType *newbase, *q, *p;
	if (i<1||i>L.length+1)
	{
		return ERROR;
	}
	if (L.length >= L.listsize)  // 当前存储空间已满，增加分配
	{
		if (!(newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType))))
		{
			exit(OVERFLOW); // 存储分配失败
		}
		L.elem = newbase; // 新基址
		L.listsize += LISTINCREMENT; // 增加存储容量
	}
	q = L.elem + i - 1;  // q为插入位置
	for (p = L.elem + L.length - 1; p >=q;--p) // 插入位置及之后的元素右移
	{
		*(p + 1) = *p;
	}
	*q = e; // 插入e
	++L.length;  // 表长增1
	return OK;
}

// 22-450，到99-450，第2章才结束