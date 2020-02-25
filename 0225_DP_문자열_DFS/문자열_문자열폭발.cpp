
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<char> s;
string str1; //입력 문자열 
string str2; //폭발 문자열 
bool ans;
int num = 0;

int main(void) {

	cin >> str1 >> str2;

	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 0; i < len1; i++) {
		ans = true;
		s.push_back(str1[i]);
		int n = i - num; //pop된 횟수만큼 vector의 인덱스 감소 


		for (int j = len2 - 1; j >= 0; j--) { // 폭발 문자열의 끝과 벡터의 끝부터 차례대로 원소 비교 
			if (s[n--] == str2[j])
				continue;
			else {
				ans = false;
				break;
			}
		}
		if (ans)  //폭발 문자열이 들어있다면 pop시킴 
			for (int k = 0; k < len2; k++) {
				s.pop_back();
				num++; //pop된 횟수 
			}
	}
	if (s.empty())
		cout << "FRULA";
	else
		for (auto x : s)
			cout << x;
	return 0;

}
