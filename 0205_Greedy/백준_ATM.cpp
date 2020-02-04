#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	int time[1000];
	int sum = 0;

	cin >> n;

	for (int i = 0;i < n;i++)
		cin >> time[i];

	sort(time, time + n); //작은것부터 더해나가야 최소값이 됨

	for (int i = 0;i < n;i++)
		for (int j = 0; j <= i;j++)
			sum += time[j];

	cout << sum << endl;

}
