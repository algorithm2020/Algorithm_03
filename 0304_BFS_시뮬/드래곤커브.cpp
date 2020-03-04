#include <iostream>
#include <vector>

using namespace std;

bool map[102][102] = { false, };
int N, x, y, d, g;
int cnt = 0;
vector<int> dir;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dragoncurv()
{
	for (int i = 0; i < N;i++)
	{
		cin >> x >> y >> d >> g;

		dir.clear();

		map[x][y] = true;
		x += dx[d]; y += dy[d];
		map[x][y] = true;
		dir.push_back(d);

		for (int j = 0; j < g;j++)
		{
			int sz = dir.size();

			for (int k = sz - 1;k >= 0;k--)
			{
				int nd = (dir[k] + 1) % 4;
				x += dx[nd]; y += dy[nd];
				map[x][y] = true;
				dir.push_back(nd);
			}
		}

	}
}

int main()
{
	cin >> N;
	
	dragoncurv();

	for (int i = 0; i < 101;i++)
	{
		for (int j = 0; j < 101;j++)
		{
			if (map[i][j] == true && map[i + 1][j] == true && map[i][j + 1] == true && map[i + 1][j + 1] == true)
			{
				cnt++;
			}
		}
	}

	cout << cnt<< '\n';

	return 0;
}
