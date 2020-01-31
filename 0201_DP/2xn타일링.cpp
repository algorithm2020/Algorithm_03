#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int d[1000];
	d[1] = 1;
	d[2] = 2;

	cin >> n;
	if (n >= 3)
		for (int i = 3; i <= n; i++)
			d[i] = (d[i - 1] + d[i - 2]) % 10007;

	cout << d[n] << endl;

}


