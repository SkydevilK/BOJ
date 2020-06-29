#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct pos {
	int x, y;
};
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
char map[100][100];
bool visit[100][100];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int normal = 0, obstacle = 0;
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j)
		{
			map[i][j] = s[j];
		}
	}
	// R(빨강), G(초록), B(파랑)
	queue<pos> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j]) {
				char now = map[i][j];
				q.push({ i, j });
				++normal;
				while (!q.empty()) {
					pos cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || map[nx][ny] != now)
							continue;
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visit[i][j]) {
				char now = map[i][j];
				q.push({ i, j });
				++obstacle;
				while (!q.empty()) {
					pos cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.x + dx[dir];
						int ny = cur.y + dy[dir];
						if (now == 'R' || now == 'G') {
							if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || map[nx][ny] == 'B')
								continue;
							visit[nx][ny] = true;
							q.push({ nx, ny });
						}
						else {
							if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || map[nx][ny] != 'B')
								continue;
							visit[nx][ny] = true;
							q.push({ nx, ny });
						}
					}
				}
			}
		}
	}
	cout << normal << " " << obstacle;
}
