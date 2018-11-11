// ��� PriorityQueue.cpp�����ݣ�����������һ����
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main()
{
	char com[20];
	//��׼���е�priority_queue
	priority_queue<int> PQ;

	while (1)
	{
		scanf("%s", com);
		if (com[0] == 'i')
		{
			int key;
			scanf("%d", &key);  // ��cin���ٶȿ�
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