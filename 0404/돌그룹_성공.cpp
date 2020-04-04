#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int a, b, c;
int sum = 0;

bool visit[1500][1500]; //1500으로 해줘야함

void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(a,b));
	visit[a][b] = true;

	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		if (x == y && y == z) {
			cout << 1 << '\n';
			return;
		}
		else {
			if (x < y && visit[x + x][y - x] == false) {
				visit[x + x][y - x] = true;
				q.push(make_pair(x+x, y-x));
			}
            if (x > y && visit[x - y][y + y] == false) {
				visit[x - y][y + y] = true;
				q.push(make_pair(x-y, y+y));
			}

			if (y < z && visit[x][y + y] == false) {
				visit[x][y + y] = true;
				q.push(make_pair(x, y+y));
			}
            if (y > z && visit[x][y - z] == false) {
				visit[x][y - z] = true;
				q.push(make_pair(x, y-z));
			}

			if (x < z && visit[x + x][y] == false) {
				visit[x + x][y] = true;
				q.push(make_pair(x+x, y));
			}
            if (x > z && visit[x - z][y] == false) {
				visit[x - z][y] = true;
				q.push(make_pair(x-z, y));
			}
		}
	}	
    cout << 0 << '\n';
}

int main()
{
	cin >> a >> b >> c;

	sum = a + b + c;
	memset(visit, false, sizeof(visit));

	if (sum%3 != 0) cout << 0 << '\n';
	else bfs();

	return 0;
}
