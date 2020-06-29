#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N, M, K;
int map[50][50];
int visit[50][50];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, x, y,count;
	cin >> T;
	while (T--)
	{
		queue<pair<int, int>> q;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> M >> N >> K;
		count = 0;
		while (K--)
		{
			cin >> y >> x;
			map[y][x] = 1;
		}
		for (int y = 0; y < M; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (map[y][x] == 1&&!visit[y][x])
				{
					q.push({ y, x });
					visit[y][x] = true;
					while (!q.empty())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						int ny = y - 1;
						int nx = x;
						if (ny >= 0 && !visit[ny][nx]&&map[ny][nx]==1)
						{
							visit[ny][nx] = true;
							q.push({ ny,nx });
						}
						ny = y;
						nx = x - 1;
						if (nx >= 0 && !visit[ny][nx] && map[ny][nx] == 1)
						{
							visit[ny][nx] = true;
							q.push({ ny,nx });
						}
						ny = y + 1;
						nx = x;
						if (ny < M && !visit[ny][nx] && map[ny][nx] == 1)
						{
							visit[ny][nx] = true;
							q.push({ ny,nx });
						}
						ny = y;
						nx = x + 1;
						if (nx < N && !visit[ny][nx] && map[ny][nx] == 1)
						{
							visit[ny][nx] = true;
							q.push({ ny,nx });
						}
					}
					++count;
				}
			}
		}
		cout << count << "\n";
	}
}
