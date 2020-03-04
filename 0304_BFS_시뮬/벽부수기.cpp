#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define MAX 1000

bool visit[MAX][MAX][2] ; //해당좌표에서 벽부쉈는지 안부쉈는지까지 봐야함
int map[MAX][MAX] ;
//int dist[1001][1001] ;
int n, m;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1))); // {x,y},{벽부순횟수,현재거리}
	visit[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int b = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1)
		{
			return cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{

				if (map[nx][ny] == 1 && b == 0 && visit[nx][ny][b] == false) // 벽인데 아직 안부순경우
				{
					visit[nx][ny][b + 1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(b + 1, cnt + 1)));
				}
				else if (map[nx][ny] == 0 && visit[nx][ny][b] == false) //벽아닌데 
				{
					visit[nx][ny][b] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(b, cnt + 1)));
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n;i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m;j++)
		{
			int a = str[j] - '0';
			map[i][j] = a;
		}
	}

	int result = bfs(); 
	cout << result << '\n';


	return 0;
}
