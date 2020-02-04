#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, k;
	int cnt = 0;

	cin >> n >> k;

	vector<int> coin(n);

	for (int i = 0;i < n;i++)
		cin >> coin[i];

	for (int j = n-1;j >= 0;j--) {
		while (k - coin[j] >= 0) {
			k -= coin[j];
			cnt++;

		}
	}

	cout << cnt <<endl ;

}
