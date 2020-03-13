#include <iostream>
#include <cstring>

using namespace std;
int w, h,nx,ny,num;
int map[51][51];
bool visit[51][51];
int dx[] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dy[] = { 0, 1, 0 , -1, -1, 1,-1, 1 };


void dfs(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 8;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < h && ny >= 0 && ny < w)
		{
			if (visit[nx][ny] == false && map[nx][ny] == 1)
			{
				visit[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
	
}


int main()
{
	while (1)
	{
		num = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		cin >> w >> h;

		if (w == 0 && h == 0) return 0;

		for (int i = 0;i < h;i++)
		{
			for (int j = 0;j < w;j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0;i < h;i++)
		{
			for (int j = 0;j < w;j++)
			{
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					num++;
					dfs(i, j);
				}
			}
		}
		cout << num << '\n';

		
	}
	return 0;
}
