// main1-1.cpp �����������bo1-1.cpp��������
#include "c1.h"
typedef int ElemType;
//typedef double ElemType;
#include "c1-1.h"
//#include "bo1-1.cpp"   // ����д���ᱨ��İɣ�������c1-1.h��������һ��bo1-1.cpp��ʵ�ֵ�
using namespace std;

void main()
{
	Triplet T;
	ElemType m;
	Status i;
	i = InitTriplet(T,5,7,9);
	printf("���ó�ʼ��������i=%d(1:�ɹ�)T��3��ֵΪ��",i);
	cout <<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;   // Ϊ����ElemType�����ͱ仯��Ӱ�죬��coutȡ��printf()��ע���βҪ��endl
	i = Get(T,2,m);  // ����Ԫ��T�ĵ�2��ֵ����m
	if(i == OK)
		cout<<"T�ĵ�2��ֵΪ��"<<m<<endl;
	i = Put(T,2,6);   // ����Ԫ��T�ĵ�2��ֵ��Ϊ6
	if(i==OK) // ����Put()�ɹ�
		cout<<"��T�ĵ�2��ֵ��Ϊ6��T��3��ֵΪ��"<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
	i=IsAscending(T); // ���ຯ��ʵ����ElemType�������޹�,��ElemType�����ͱ仯ʱ,ʵ�β���ı�
	printf("���ò�������ĺ�����i=%d(0:�� 1:��)\n",i);
	i=IsDescending(T);
	printf("���ò��Խ���ĺ�����i=%d(0:�� 1:��)\n",i);
	if((i=Max(T,m))==OK) // �ȸ�ֵ�ٱȽ�
		cout<<"T�е����ֵΪ��"<<m<<endl;
	if((i=Min(T,m))==OK)
		cout<<"T�е���СֵΪ��"<<m<<endl;
	DestroyTriplet(T); // ����Ҳ���Բ����ط���ֵ
	cout<<"����T��T="<<T<<"(NULL)"<<endl;
}
