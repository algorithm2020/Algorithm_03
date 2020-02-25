#include <iostream>
#include <string>
#include <queue>

using namespace std;

string str1, str2;
queue<int> q;

int main()
{
	cin >> str1 >> str2;

	//cout << str1.find(str2);
	
	int sz = str2.size(); //찾아야할 문자 사이즈
	q.push(0);

	while (!q.empty())
	{
		q.pop();
		int first = str1.find(str2);
		if (first == -1) break;
		str1.erase(first, sz);
		q.push(first);
	}

	if (str1 == "") cout << "FRULA";
	else cout << str1;
	
	return 0;
}
