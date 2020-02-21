//테스트케이스는 다 맞는데 백준에서 틀림 

#include <iostream>
#include <queue>
#include <cstring> //memset 필요

using namespace std;

int n, m;
int answer = 0;
int water[51][51];
char map[51][51];
bool visit[51][51];

queue<pair<int, int>> q;
queue<pair<int, int>> wt_q;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };


void watertime() // 물차는시간 저장
{
	while (!wt_q.empty())
	{
		int a = wt_q.front().first;
		int b = wt_q.front().second;
		visit[a][b] = true;
		wt_q.pop();

		for (int i = 0; i < 4;i++)
		{
			int na = a + dx[i];
			int nb = b + dy[i];

			if (na<0 || na>n || nb<0 || nb>m) continue;
			if (visit[na][nb] == false && map[na][nb] == '.' && water[na][nb] < water[a][b] + 1)
			{
				water[na][nb] = water[a][b] + 1;
				visit[na][nb] = true;
				wt_q.push({ na,nb });
			}
		}
	}
}

void kosumdochi()
{
	int move[51][51];
	memset(move, 0, sizeof(move));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n || ny<0 || ny>m) continue;
			if (visit[nx][ny] == false && map[nx][ny] != 'X' && map[nx][ny] != '*')
			{
				if (map[nx][ny] == 'D')
				{
					answer = move[x][y] + 1;
					break;
				}
				if (move[x][y] + 1 < water[nx][ny])
				{
					move[nx][ny] = move[x][y] + 1;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n; i++)
		for (int j = 0;j < m;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*') wt_q.push({ i,j }); //물bfs 시작점
			if (map[i][j] == 'D') water[i][j] = -1;
			if (map[i][j] == 'X') water[i][j] = -1;
			if (map[i][j] == 'S') q.push({ i,j });//고슴도치bfs 시작점
		}

	watertime();
	memset(visit, false, sizeof(visit));
	kosumdochi();

	if (answer > 0) cout << answer;
	else cout << "KAKTUS";

	/*
	for (int i = 0;i < n; i++)
	{
	cout << '\n';
	for (int j = 0;j < m;j++)
	cout << water[i][j];
	}*/

	return 0;
}
