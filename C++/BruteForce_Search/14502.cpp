#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int map[8][8];
bool visit[8][8];
bool visit2[8][8];
queue<pair<int, int>>q;
vector<pair<int, int>>v;
int _max = 0;
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
void BFS()
{
	int m[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j) {
			m[i][j] = map[i][j];
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < v.size(); ++i)
	{
		q.push(v[i]);
		visit[v[i].first][v[i].second] = true;
	}
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || m[nx][ny] != 0)
			{
				continue;
			}
			q.push({ nx,ny });
			visit[nx][ny] = true;
			m[nx][ny] = 2;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (m[i][j] == 0)
			{
				++cnt;
			}
		}
	}
	_max = _max < cnt ? cnt : _max;
}
void DFS(int count, int x, int y)
{
	if (count == 3)
	{
		BFS();
	}
	else
	{
		for (int i = x; i < N; ++i)
		{
			for (int j = y; j < M; ++j)
			{
				if (!visit2[i][j])
				{
					map[i][j] = 1;
					visit2[i][j] = true;
					DFS(count + 1, x, y);
					map[i][j] = 0;
					visit2[i][j] = false;
				}
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				v.push_back({ i,j });
			}
			if (map[i][j] == 2 || map[i][j] == 1)
			{
				visit2[i][j] = true;
			}
		}
	}
	DFS(0, 0, 0);
	cout << _max;
	return 0;
}
