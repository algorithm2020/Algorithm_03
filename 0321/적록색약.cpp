#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N;
char map[101][101];
bool visit[101][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (visit[nx][ny] == false && map[nx][ny] == map[x][y]) //색이 같은 경우
				{
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					
				}
			}
		}
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt, cnt2;
	cnt = cnt2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == false)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == false)
			{
				bfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt << " " << cnt2 << endl;

	return 0;
}
