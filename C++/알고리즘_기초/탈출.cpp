// BOJ 3055
#include <iostream>
#include <queue>
using namespace std;
struct m {
	int x, y, s;
};
int R, C, sx, sy;
char map[51][51];
int answer[51][51];
queue<m> q;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void bfs() {
	q.push({ sx, sy, 1 });
	answer[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().s;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (map[nx][ny] == 'X' || answer[nx][ny])
				continue;
			if (map[nx][ny] == 'D') {
				if (s == 0) continue;
				cout << answer[x][y];
				return;
			}
			answer[nx][ny] = answer[x][y] + 1;
			q.push({ nx, ny, s });
		}
	}
	cout << "KAKTUS";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				q.push({ i, j, 0 });
				answer[i][j] = 1;
			}
			else if (map[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}
	bfs();
	return 0;
}
