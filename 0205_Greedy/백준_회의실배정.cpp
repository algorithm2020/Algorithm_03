//실패

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n,x,y,a,cnt;
	vector<pair<int, int>> time;
	cin >> n;

	for (int i = 0;i < n;i++)
		cin >> x >> y;
		time.push_back(pair<int, int>(x, y));

	sort(time.begin(), time.end());

	a = 0;
	cnt = 1;

	for (int i = 0;i < n;i++)
		if (time[i].first > time[a].second)
			a = time[i].second;
			cnt += 1;

	cout << cnt << endl;

	return 0;
}
