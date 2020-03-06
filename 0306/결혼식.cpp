#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, v, w;
vector<bool> check ; //방문햇는지체크
vector<vector<int>> f; //친구관계
queue<int> q;
vector<int> invite; //초대 가능한 친구들
int cnt[501];

void bfs()
{
	q.push(1);
	cnt[1] = 0;
	check[1] = true;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		if (cnt[a] == 2) break; //cnt 2면 친구의 친구

		for (int i = 0; i < f[a].size();i++)
		{
			if (check[f[a][i]] == false)
			{
				q.push(f[a][i]);
				invite.push_back(f[a][i]);
				cnt[f[a][i]] = cnt[a] + 1;
				check[f[a][i]] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	f.resize(n+1);
	check.resize(n+1);



	for (int i = 0; i < m; i++)
	{
		cin >> v >> w;
		f[v].push_back(w);
		f[w].push_back(v);

	}

	bfs();

	cout << invite.size() << '\n';
	return 0;
}
