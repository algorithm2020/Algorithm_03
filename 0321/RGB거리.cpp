#include <iostream>
#include <algorithm>

using namespace std;
int N, result;
int dp[1001][3];
int color[1001][3];

void findMin()
{
	color[0][0] = color[0][1] = color[0][2] = 0;
	dp[0][0] = color[0][1] = color[0][2] = 0;

//dp[i][0] : i번째 집에서 빨간색을 칠할 경우 다른 집을 색칠하는 최소 비용.
	for (int i = 1;i <= N;i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}
	result = min(min(dp[N][0], dp[N][1]), dp[N][2]); //min함수 두개씩 해줘야함!

	cout << result << '\n';
}

int main()
{
	cin >> N;

	for (int i = 1;i <= N;i++)
	{
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}
	findMin();

	return 0;
}
