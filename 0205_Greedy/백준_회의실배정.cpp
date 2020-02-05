//실패

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n,x,y,a,cnt;
	int cBegin[100000], cEnd[100000];
	vector<pair<int, int>> time;
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> cBegin[i] >> cEnd[i];
	for (int i = 0; i < n; i++)
		time.push_back(make_pair(cEnd[i], cBegin[i]));

	sort(time.begin(), time.end());

	a = time[0].first;
	cnt = 1;

	for (int i = 0;i < n;i++)
		if (time[i].second > a)
		{
			a = time[i].first;
			cnt ++;
		}
	cout << cnt << endl;

	return 0;
}
