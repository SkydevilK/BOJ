#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,0,-1,1 };
const int dy[] = { 0,-1,1,0,0 };


struct Perfume
{
	int sharkIdx, time;
};

struct Map
{
	int x, y, sharkIdx, time;
};

bool cmp(Map a, Map b)
{
	return a.sharkIdx < b.sharkIdx;
}

int N, M, K;
int sharkMap[20][20];

Perfume sharkPerfume[20][20];

int sharkDirection[401];

int movePriority[401][5][5];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			int sharkIdx;
			cin >> sharkIdx;

			if (sharkIdx == 0)
			{
				continue;
			}

			sharkMap[y][x] = sharkIdx;
			sharkPerfume[y][x].sharkIdx = sharkIdx;
			sharkPerfume[y][x].time = K;
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		cin >> sharkDirection[i];
	}

	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			for (int k = 1; k <= 4; ++k)
			{
				int move;
				cin >> move;

				movePriority[i][j][k] = move;
			}
		}
	}

	for (int t = 1; t <= 1000; ++t)
	{
		vector<Map> v;

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (sharkMap[y][x] == 0)
				{
					continue;
				}
				bool isCheck = false;
				int sharkIdx = sharkMap[y][x];
				int dir = sharkDirection[sharkIdx];

				sharkMap[y][x] = 0;

				for (int k = 1; k <= 4; ++k)
				{
					int move = movePriority[sharkIdx][dir][k];

					int nx = x + dx[move];
					int ny = y + dy[move];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					{
						continue;
					}
					if (sharkPerfume[ny][nx].time)
					{
						continue;
					}
					isCheck = true;
					v.push_back({ nx, ny, sharkIdx, K });
					sharkDirection[sharkIdx] = move;
					break;
				}
				if (isCheck)
				{
					continue;
				}
				for (int k = 1; k <= 4; ++k)
				{
					int move = movePriority[sharkIdx][dir][k];
					int nx = x + dx[move];
					int ny = y + dy[move];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					{
						continue;
					}

					if (sharkPerfume[ny][nx].sharkIdx != sharkIdx)
					{
						continue;
					}
					v.push_back({ nx, ny, sharkIdx, K });
					sharkDirection[sharkIdx] = move;
					break;
				}
			}
		}
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (sharkPerfume[y][x].time == 0)
				{
					continue;
				}
				--sharkPerfume[y][x].time;
			}
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); ++i)
		{
			int x = v[i].x;
			int y = v[i].y;
			int sharkIdx = v[i].sharkIdx;
			if (sharkMap[y][x])
			{
				--M;
				continue;
			}

			sharkMap[y][x] = sharkIdx;
			sharkPerfume[y][x].sharkIdx = sharkIdx;
			sharkPerfume[y][x].time = K;
		}
		if (M == 1)
		{
			cout << t << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";

	return 0;
}
