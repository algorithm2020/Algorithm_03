#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	queue<int> q;

	cin >> N >> M;

	for (int i = 1;i < N + 1;i++)  // 1~N 값의 큐 생성
	{
		q.push(i);
	}

	cout << "<";
	while (!q.empty())
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
			break;
		}

		for (int i = 1;i < M;i++)
		{
			q.push(q.front());
			q.pop();
				
		}

		cout << q.front() << ", ";
		q.pop();
			
	}
	return 0;
}
