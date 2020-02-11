#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
char arr[20];

void backTracking(int start, string str, int ja, int mo)
{
	if (str.size() == L)
	{
		if (ja < 2 || mo < 1)
			return;

		cout << str << '\n';
	}

	for (int i = start; i < C; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			backTracking(i + 1, str + arr[i], ja, mo + 1);
		else
			backTracking(i + 1, str + arr[i], ja + 1, mo);
	}
}


int main()
{
	
	cin >> L >> C;

	for (int i = 0;i < C;i++)
		cin >> arr[i];
	
	sort(arr, arr + C);

	backTracking(0, "", 0, 0);

	return 0;

}
