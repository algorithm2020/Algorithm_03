#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

char map[12][6]; //입력받은 배열
bool check[12][6] ;//방문했는지 체크하는 배열
queue<pair<int,int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
//int cnt = 0;
int res = 0;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
		return false;
	}
	return false;
}

void bfs()
{
	while (1)
	{
		memset(check, false, sizeof(check));
		vector<pair<int, int>> pusija;
		for (int x = 11; x >= 0; x--)
		{
			for (int y = 0; y < 6; y++)
			{
				if (map[x][y] == '.')
					continue;
				else
				{
					queue<pair<int, int>> cnt;
					check[x][y] = true;
					q.push(make_pair(x, y));


					while (!q.empty())
					{
						
						int a= q.front().first;
						int b = q.front().second;
						//cout << a << b<<'\n';
						cnt.push({ a, b });
						q.pop();

						for (int i = 0; i < 4;i++) //위 아래 왼 오 방향으로 탐색
						{
							int nx = a + dx[i];
							int ny = b + dy[i];

							//cout << map[a][b] << 'a' << map[nx][ny]<<'\n';

							if (0<=nx && nx < 12 && 0<=ny && ny < 6)
							{
								if (check[nx][ny] == false &&( map[x][y] == map[nx][ny]))
								{
				
									check[nx][ny] = true;
									q.push({ nx, ny });
								}
							}
						}
					}


					if (cnt.size() >= 4) { //똑같은 문자가 4개이상만나서 터지는 경우
						while (!cnt.empty()) {
							pusija.push_back({ cnt.front().first,cnt.front().second });
							cnt.pop();
						}
					}
				}
			}
		}

		if (pusija.size() >= 4) //팡
		{
			sort(pusija.begin(), pusija.end(), cmp);
			for (int i = 0; i < pusija.size(); i++)
			{

				for (int j = pusija[i].first; j > 0; j--)

					map[j][pusija[i].second] = map[j - 1][pusija[i].second];

				map[0][pusija[i].second] = '.';

			}

			res++; 

		}
		else
			break;


	}

}

int main()
{
	for (int i = 0; i < 12;i++)
		for (int j = 0; j < 6;j++)
			cin >> map[i][j];
    	bfs();
	cout << res;

	return 0;

}
