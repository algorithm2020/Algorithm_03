#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a[1001], c[1001];
	int n;
	int cnt = 0;

	cin >> n;

    for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
  
  
	for (int i = 0; i < n; i++)
	{
		c[i] = 1; //처음길이는 1로 시작
    
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && c[j] + 1 > c[i]) // i값에서 i보다 작은 j값들과 비교
				c[i] = c[j] + 1;

		}
		cnt = max(cnt, c[i]);
	}
	cout << cnt;
}
