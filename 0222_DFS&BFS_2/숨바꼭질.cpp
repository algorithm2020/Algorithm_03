// BFS 풀이

#include <iostream>
#include <queue>

using namespace std;


int N, K;
int cnt = 0;
queue<int> q;
bool visit[100001];
int dist[100001]; 

void bfs(int x )
{
	q.push(x);
	visit[x] = true;
	dist[x] = 0;
	
	while (!q.empty())
	{
		int a = q.front();

		if (a == K) {
			cout << dist[a] << '\n';
			break;
		}
	
		if (visit[a - 1] == false && a - 1 >= 0 && a-1 <=100000) { //x-1 이동한 경우
			visit[a - 1] = true;
			dist[a - 1] = dist[a] + 1;
			q.push(a - 1);
		}

		if (visit[a + 1] == false && a + 1 >= 0 && a+1 <= 100000) { //x+1 이동한 경우
			visit[a + 1] = true;
			dist[a + 1] = dist[a] + 1;
			q.push(a + 1);
		}

		if (visit[2*a] == false && 2*a >= 0 && 2*a <= 100000) { //2*x 이동한 경우
			visit[2*a] = true;
			dist[2*a] = dist[a] + 1;
			q.push(2*a);
		}
		q.pop();
		
	}
}

int main()
{
	cin >> N >> K;

	bfs(N);

	return 0;
}
