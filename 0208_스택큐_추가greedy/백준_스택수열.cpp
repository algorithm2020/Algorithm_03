#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, a;
	stack<int> s;
	queue<int> q;
	vector<char> res;

	cin >> N;

	for (int i = 0; i < N; i++) // 만들어야할 배열 큐 생성
	{
		cin >> a;
		q.push(a);
	}

	for (int i = 1; i < N + 1; i++) // 1,2,3 차례로 스택에 넣음
	{
		s.push(i);
		res.push_back('+');


		while (!s.empty() && s.top() == q.front()) //s.empty()처리안해주면 런임에러
		{
			res.push_back('-');
			q.pop();
			s.pop();
		}
	}

	if (!s.empty())
		cout << "NO" << '\n';

	else for (auto x : res)
		cout << x << '\n';

	return 0;
}
