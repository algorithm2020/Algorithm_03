//DP?????? DFS로 품.
//삼성역량테스트 기출문제

#include <iostream>
#include <algorithm>

using namespace std;
int N;
int time[17];
int cost[17];
int result;

void findMax(int day, int total)
{
	if (day > N) //day==N 일때 계산하는 경우도 있어서 '>'로 해줌.
	{
		result = max(result, total);
		return;
	}
	
	// day에 상담가능한 경우,
	if (day + time[day] <= N + 1) findMax(day + time[day], total + cost[day]);
	// day에 상담하지 않는 경우,
	if (day + 1 <= N + 1) findMax(day + 1, total);

}

int main()
{
	cin >> N;

	for (int i = 1; i < N+1;i++)
	{
		cin >> time[i] >> cost[i];
	}

	findMax(1,0);
	cout << result << '\n';

	return 0;
}
