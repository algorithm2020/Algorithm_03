#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
int cup[3];
bool visit[201][201];
int from[] = { 0,0,1,1,2,2 };
int to[] = { 1,2,0,2,0,1 };

queue<pair<int, int>> q;
vector<int> ans;

void bfs()
{
	q.push({ 0,0 });
	visit[0][0] = true;
	ans.push_back(cup[2]);
	int sum = cup[2];
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;

		q.pop();
		for (int i = 0;i < 6;i++)
		{
			int move[3] = { x,y,z };
			move[to[i]] += move[from[i]];
			move[from[i]] = 0;

			if (move[to[i]] >= cup[to[i]]) {
				move[from[i]] = move[to[i]] - cup[to[i]];
				move[to[i]] = cup[to[i]];
				
			}
			if (!visit[move[0]][move[1]])
			{
				visit[move[0]][move[1]] = true;
				q.push({ move[0],move[1] });
				if (move[0] == 0) ans.push_back(move[2]);
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 3;i++)
	{
		cin >> cup[i];
	}

	bfs();

	sort(ans.begin(), ans.end());

	for (auto x : ans)
	{
		cout << x<<" ";
	}
	return 0;

}
