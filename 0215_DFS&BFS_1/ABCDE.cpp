#include <iostream>
#include <vector>

using namespace std;

vector<bool> check;
vector<vector<int>> f;
int n, k, u, v;
bool ans;
//int res = 0;

void dfs(int x, int cnt)
{
	check[x] = true;

	if (cnt == 4) {
		ans = true;
		return;
	}

	for (int i = 0; i < f[x].size();i++)
	{
		int now = f[x][i];
		if (check[now] == false)
		{
			dfs(now, cnt + 1);
		}
	}
	check[x] = false;
	}

int main()
{

	cin >> n >> k; //n:사람명수 k:관계의수
	f.resize(n);
	check.resize(n);

	for (int i = 0;i < k;i++)
	{
		cin >> u >> v;

		f[u].push_back(v);
		f[v].push_back(u);

	}

	for (int i = 0;i < n;i++)
	{
		dfs(i, 0);
		if (ans == true) break;
	}

	if (ans == true) cout << 1 << '\n';
	else cout << 0 << '\n';

	return 0;
}
