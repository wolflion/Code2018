#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> PQ;
	PQ.push(1);
	PQ.push(8);
	PQ.push(3);
	PQ.push(5);

	cout << PQ.top() << " ";  // 8

	PQ.pop();

	cout << PQ.top() << " ";  // 5
	PQ.pop();

	PQ.push(11);
	cout << PQ.top() << " ";  // 11
	PQ.pop();

	cout << PQ.top() << endl;  // 3
	PQ.pop();

	return 0;
}

//8 5 11 3