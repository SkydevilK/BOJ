#include<iostream>
using namespace std;
int map[51][51];
int _count = 0;
int d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, r, c;
	cin >> N >> M >> r >> c >> d;

	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			cin >> map[x][y];
		}
	}
	bool flag = false;
	bool isLoop = true;
	while (isLoop)
	{
		if (map[r][c] == 0)
			_count++;
		map[r][c] = 2;
		for (int i = 0; i < 4; ++i)
		{
			flag = false;
			--d;
			if (d < 0)
				d = 3;
			switch (d)
			{
			case 0:
				if (map[r - 1][c] == 0 && map[r - 1][c] != 2)
				{
					--r;
					flag = true;
				}
				break;
			case 1:
				if (map[r][c + 1] == 0 && map[r][c + 1] != 2)
				{
					++c;
					flag = true;
				}
				break;
			case 2:
				if (map[r + 1][c] == 0 && map[r + 1][c] != 2)
				{
					++r;
					flag = true;
				}
				break;
			case 3:
				if (map[r][c - 1] == 0 && map[r][c - 1] != 2)
				{
					--c;
					flag = true;
				}
				break;
			}
			if (flag)
			{
				break;
			}
		}
		if (!flag)
		{
			switch (d)
			{
			case 0:
				if (map[r + 1][c] != 1)
				{
					++r;
				}
				else
				{
					isLoop = false;
				}
				break;
			case 1:
				if (map[r][c - 1] != 1)
				{
					--c;
				}
				else
				{
					isLoop = false;
				}
				break;
			case 2:
				if (map[r - 1][c] != 1)
				{
					--r;
				}
				else
				{
					isLoop = false;
				}
				break;
			case 3:
				if (map[r][c + 1] != 1)
				{
					++c;
				}
				else
				{
					isLoop = false;
				}
				break;
			}
		}
		if (map[r + 1][c] != 0 && map[r][c - 1] != 0 && map[r][c + 1] != 0 && map[r - 1][c] != 0)
		{
			switch (d)
			{
			case 0:
				if (map[r + 1][c] == 1)
					isLoop = false;
				break;
			case 1:
				if (map[r][c - 1] == 1)
					isLoop = false;
				break;
			case 2:
				if (map[r - 1][c] == 1)
					isLoop = false;
				break;
			case 3:
				if (map[r][c + 1] == 1)
					isLoop = false;
				break;
			}
		}
	}
	cout << _count;
}
