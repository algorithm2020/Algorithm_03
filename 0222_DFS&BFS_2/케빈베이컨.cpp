//BFS 풀이

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<int> q;
bool visit[101]; //방문했는지 확인
int dist[101]; //몇명통과해야하는지 알기위해
int sum[101]; //각 사람의 
int map[101][101];
int N, M,a,b;


void bfs(int x)
{
	q.push(x);
	visit[x] = true;
	dist[x] = 0;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int i = 1;i <= N;i++)
		{
			if (map[a][i] == 1 && visit[i] == false)
			{
				visit[i] = true;
				q.push(i);
				dist[i] = dist[a] + 1;
			}
		}
	}
}

int min() //
{
	int min = sum[1];
	int min_person = 1;

	for (int i = 2;i <= N;i++)
	{
		if (min > sum[i])
		{
			min = sum[i];
			min_person = i;
		}
	}

	return min_person;
}

int main()
{
	cin >> N >> M;

	for (int i = 0;i < M;i++) //친구관계인것은 1.
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for (int j = 1;j <= N;j++) // j->K 까지의 최소거리 합.
	{
		bfs(j);
		for (int k = 1;k <= N;k++)
		{
			sum[j] += dist[k];
		}
		memset(visit, false, sizeof(visit));
		memset(dist, 0, sizeof(dist));
	}

	int res = min();
	cout << res <<'\n';

	return 0;
}
