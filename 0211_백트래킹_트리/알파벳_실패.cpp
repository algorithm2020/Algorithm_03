#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m,cx,cy;
char arr[21][21];
vector<char> visited;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 }; //오른쪽 아래 왼쪽 위
int cnt = 0;

int dfs(int x, int y)
{
	visited.push_back(arr[x][y]);

	int max;
	for (int i = 0;i < 4;i++)
	{	
		max = 0;
		cx = x + dx[i];
		cy = y + dy[i];

		if (cy<0 || cy >= n || cx<0 || cx >= m)
			continue;

		for (int j = 0;j < visited.size();j++)
		{
			if (arr[cx][cy] != visited[j]) {
				cnt++;
				dfs(cx, cy);
			}
		}
	}


	return cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for(int j=0;j<m;j++)
			cin >> arr[i][j];
	

	dfs(0, 0);
	cout << cnt;

	return 0;
}
