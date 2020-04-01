//실버2치고 좀 짜증나는 문제...

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string str;
int sum,a,b; //a,b값으로 같은 괄호를 count 해서 에러를 없앨수있었음.
int gop = 1;

int main()
{

	cin >> str;

	stack<char> stack;
	for (int i = 0;i<str.length();i++) {
		char now = str[i];

		if (now == '(') {
			a++;
			gop *= 2;
			stack.push(now);
			if (i + 1 < str.length() && str[i + 1] == ')')
				sum += gop;
			
		}
		else if (now == '[') {
			b++;
			gop *= 3;
			stack.push(now);
			if (i + 1 < str.length() && str[i + 1] == ']')
				sum += gop;
		}

		else if (now == ')') {
			if (a > 0) {
				a--;
				gop /= 2;
				if (stack.top() == '(') stack.pop();
			}
			else {
				cout << 0 << '\n';
				return 0;
			}
		}
		else if (now == ']') {
			if (b > 0) {
				b--;
				gop /= 3;
				if (stack.top() == '[') stack.pop();
			}
			else {
				cout << 0 << '\n';
				return 0;
			}
		}
	}

	if (a!=0 || b!=0) 
		sum = 0;

	cout << sum <<'\n';

	return 0;
}
