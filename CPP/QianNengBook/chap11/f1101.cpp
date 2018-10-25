// f1101.cpp  Josephus问题过程化实现

#include <iostream>
using namespace std;

struct Jose     // 小孩结点
{
	int code;   // 小孩编号
	Jose* next;  // 指向下一个小孩结点
};

int n,s,m;
Jose *pCur,*pivot;

bool getValue();
Jose* createRing();   // 创建环链表
void countBoy(int m);   // 数m个小孩
void process();    // 排除n-1个小孩

int main()
{
	if(!getValue())
		return 1;
	Jose* pJose = createRing();
	process();
	cout<<"\nThe winner is "<<pCur->code<<"\n";
	delete[] pJose;
}

bool getValue()
{
	cout<<"please input boyNumber, startPosition, intervalNumber:\n";
	cin >> n >> s >>m;
	if(n>=2 && s>=1&&s<n&&m>=1&&m<=n)
		return true;
	cerr<<"failed in bad boy Number or start Position or interval Number.\n";
	return false;
}

Jose* createRing()
{
	Jose* px = new Jose[n];
	for (int i = 1; i <= n; ++i)
	{
		px[i-1].next = &px[i%n];
		px[i-1].code = i;
	}
	cout<<"There are "<<n<<" boys.\n";
	pivot = &px[n-2];
	pCur = &px[n-1];
	countBoy(s-1);
	return px;
}

void countBoy(int m)
{
	for(int i =0;i<m;++i)
	{
		pivot = pCur;
		pCur = pivot->next;
	}
}

void process()
{
	for (int i=1;i<n;++i)
	{
		countBoy(m);
		static int line = 0;
		cout << " "<<pCur->code;
		if(!(++line%10))
			cout<<"\n";
		pivot->next = pCur->next;  // 小孩脱链
		pCur = pivot;
	}
}