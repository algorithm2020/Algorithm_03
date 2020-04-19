#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M, T;
int map[51][51];
int x, d, k;
queue<pair<int, int>> q;

void remove() {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int xx, yy;
	int cmp;
	bool flag = false;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] != -1) {
				cmp = map[i][j];
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0;k < 4;k++) {
						xx = x + dx[k];
						yy = y + dy[k];

						if (xx >= 0 && xx < N) {
							if (yy >= 0 && yy < M) {
								if (map[xx][yy] == cmp && map[xx][yy] != -1) {
									map[x][y] = -1;
									map[xx][yy] = -1;
									flag = true;
									q.push({ xx,yy });
								}
							}

							else if (yy == -1) {
								if (map[xx][M - 1] == cmp && map[xx][M - 1] != -1) {
									map[x][y] = -1;
									map[xx][M-1] = -1;
									flag = true;
									q.push({ xx,M-1 });
								}
							}
							else if (yy == M) {
								if (map[xx][0] == cmp && map[xx][0] != -1) {
									map[x][y] = -1;
									map[xx][0] = -1;
									flag = true;
									q.push({ xx,0 });
								}
							}
						}
					}
				}
			}
		}
	}
	double total = 0; double num = 0;
	if (flag == false) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (map[i][j] > 0) {
					total += map[i][j];
					num++;
				}
			}
		}
		double div = total / num;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (map[i][j] > div && map[i][j] != -1) {
					map[i][j] -= 1;
				}
				else if (map[i][j] < div && map[i][j] != -1) {
					map[i][j] += 1;
				}
			}
		}
	}
}

void wonpan() {
	for (int i = 0;i < T;i++) {
		cin >> x >> d >> k;
		if (d == 0) {
			for (int r = 0;r < N;r++) {
				if ((r + 1) % x == 0) {
					for (int j = 0;j < k;j++) {
						for (int w = 0;w < M - 1;w++) {
							swap(map[r][w], map[r][M - 1]);
						}
					}
				}
			}
		}
		else {
			for (int r = 0;r < N;r++) {
				if ((r + 1) % x == 0) {
					for (int j = 0;j < k;j++) {
						for (int w = M - 1;w > 0;w--) {
							swap(map[r][0], map[r][w]);

						}
					}
				}
			}
		}
		remove();
	}
}


int main() {
	cin >> N >> M >> T;
	memset(map, 0, sizeof(map));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}
	wonpan();

	int sum = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] > 0)
				sum += map[i][j];
		}
	}

	cout << sum << '\n';
	/*
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
				cout << map[i][j] <<' ';
		}
		cout << '\n';
	}*/
	
	return 0;
}
