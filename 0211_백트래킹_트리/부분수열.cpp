#include <iostream>
#include <vector>

using namespace std;

int n, goal;
int sum = 0;
int cnt = 0;
vector<int> arr;

void dfs(int sum, int idx) {
	sum += arr[idx];

	if (idx >= n)
		return;

	if (sum == goal)
		cnt++;

	dfs(sum, idx + 1); //지금까지 더한 sum값에 다음index값 더하기
	dfs(sum - arr[idx], idx + 1);//지금더한 arr[ind]값 빼고 더하기
}


int main()
{
	cin >> n >> goal;
	arr.resize(n);

	for (int i = 0; i < n;i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << cnt <<'\n';

	return 0;
}
