#include <iostream>

using namespace std;

int n, m, x, y, d;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[51][51];
bool visit[51][51];

void moveRobot()
{
	visit[x][y] = true;
	int clean = 1;
	int nd, nx, ny;

	while (1)
	{
		int cnt = 0;
		int og_d = d;//초기방향 저장
		for (int i = 0;i < 4;i++)
		{
			//각 방향에서 왼쪽방향부터 나타내기위해
			if (d == 0) nd = 3;
			else if (d == 1) nd = 0;
			else if (d == 2) nd = 1;
			else if (d == 3) nd = 2;

			nx = x + dx[nd];
			ny = y + dy[nd];
			
			if (map[nx][ny] == 1 || visit[nx][ny] == true)
			{
				d = nd;
				cnt++;
			}
			else if (map[nx][ny] == 0)
			{
				visit[nx][ny] = true;
				clean++;
				d = nd;
				break;
			}

		}
		if (cnt == 4) //네방향 모두 벽이거나 청소한 경우
		{
			//한칸 뒤로가기
			nx = x - dx[og_d];
			ny = y - dy[og_d];
			d = og_d;
			if (map[nx][ny] == 1) break;
		}
		x = nx; y = ny;
	}
	cout << clean << '\n';
}

int main()
{
	cin >> n >> m; //map 크기
	cin >> x >> y >> d; //현재 로봇위치와 방향

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> map[i][j];
		}
	}
	moveRobot();

	return 0;
}
