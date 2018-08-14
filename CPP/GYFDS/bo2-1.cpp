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