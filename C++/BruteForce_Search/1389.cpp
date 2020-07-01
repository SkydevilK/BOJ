#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int graph[101][101];
int dist[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	while (M--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	memset(dist, -1, sizeof(dist));

	for (int i = 1; i <= N; ++i) {
		queue<int> q;
		q.push(i);
		dist[i][i] = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 1; j <= N; ++j) {
				if (dist[i][j] == -1 && graph[cur][j] == 1) {
					dist[i][j] = dist[i][cur] + 1;
					q.push(j);
				}
			}
		}
	}

	int ans = 0;
	int temp = -1;
	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 1; j <= N; ++j) {
			sum += dist[i][j];
		}
		if (temp == -1 || temp > sum) {
			temp = sum;
			ans = i;
		}
	}

	cout << ans << '\n';
	return 0;
}
