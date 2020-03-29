#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,a,b;
vector<pair<int, int>> sinip;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		
		cin >> m;
		int cmp = 0;
		int cnt = 1;
		sinip.clear();
	
		for (int j = 0;j < m;j++)
		{
			cin >> a >> b;
			sinip.push_back(make_pair(a, b));

		}

		sort(sinip.begin(), sinip.end());

		cmp = sinip[0].second;

		for (int k = 1;k < m;k++)
		{
			if (sinip[k].second < cmp)
			{
				cmp = sinip[k].second;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
