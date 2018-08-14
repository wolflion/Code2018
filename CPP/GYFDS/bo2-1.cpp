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