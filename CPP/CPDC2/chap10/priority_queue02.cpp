// 解决 PriorityQueue.cpp的内容，两个功能是一样的
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main()
{
	char com[20];
	//标准库中的priority_queue
	priority_queue<int> PQ;

	while (1)
	{
		scanf("%s", com);
		if (com[0] == 'i')
		{
			int key;
			scanf("%d", &key);  // 比cin的速度快
			PQ.push(key);
		}
		else if (com[0] == 'x')
		{
			printf("%d\n", PQ.top());
			PQ.pop();
		}
		else if (com[0] == 'e')
		{
			break;
		}
	}
	return 0;
}

/*
insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end
*/

//output
/*
8
10
11
2
*/