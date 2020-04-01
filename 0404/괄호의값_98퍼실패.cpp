// ())(, (())] 등의 경우에서 안됨 

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string str;
int sum;
int gop = 1;

int main()
{

	cin >> str;

	stack<char> stack;
	for (int i = 0;i<str.length();i++) {
		char now = str[i];

		if (now == '(') {
			gop *= 2;
			if (i + 1 < str.length() && str[i + 1] == ')')
				sum += gop;
			stack.push(now);
			
		}
		else if (now == '[') {
			gop *= 3;
			if (i + 1 < str.length() && str[i + 1] == ']') 
				sum += gop;
			stack.push(now);
			
		}

		if (!stack.empty()) {
			if (now == ')') {
				if (gop % 2 == 0) gop /= 2;
				if (stack.top() == '(') stack.pop();
			}
			else if (now == ']') {
				if (gop % 3 == 0) gop /= 3;
				if (stack.top() == '[') stack.pop();
			}
		}
	}

	if (!stack.empty())
		sum = 0;

	cout << sum ;

	return 0;
}
