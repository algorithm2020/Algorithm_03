#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int N, L, R;
int map[51][51];
bool visit[51][51];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool check = true;

bool Search(int x, int y) //해당 지점에서 bfs를 돌릴지 안돌릴지 판단하기 위해.
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (L <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= R) return true;
		}
	}
	return false;
}

void bfs(int a, int b)
{
	queue<pair<int, int>> q, nq;
	q.push(make_pair(a, b));
	nq.push(make_pair(a, b));
	visit[a][b] = true;
	int sum = 0;
	int cnt = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		sum = sum + map[x][y];
		cnt = cnt + 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny] == true) continue;
			if (L <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= R)
			{
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
				nq.push(make_pair(nx, ny));
			}
		}
	}

	int value = sum / cnt;

	while (!nq.empty())
	{
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();
		map[x][y] = value;
	}
}

int main()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int Day = 0;
	while (check)
	{
		memset(visit, false, sizeof(visit));

		check = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == false && Search(i, j) == true)
				{
					bfs(i, j);
					check = true;
				}
			}
		}
		if (check == true) Day++;
		

	}
	cout << Day << '\n';
	return 0;
}

