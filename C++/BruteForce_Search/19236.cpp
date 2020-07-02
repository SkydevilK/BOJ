#include <iostream>
#include <algorithm>
using namespace std;

const int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
const int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
struct Fish
{
	int num, dir, x, y;
};

int result;
void simulation(Fish fishes[], int map[4][4], Fish shark, int total)
{
	result = max(result, total);
	for (int i = 1; i <= 16; ++i)
	{
		int x = fishes[i].x;
		int y = fishes[i].y;
		if (fishes[i].num == 0)
		{
			continue;
		}
		for (int loop = 0; loop <= 8; ++loop)
		{
			int	nx = x + dx[fishes[i].dir];
			int	ny = y + dy[fishes[i].dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx == shark.x && ny == shark.y))
			{
				if (fishes[i].dir == 8)
					fishes[i].dir = 1;
				else
					++fishes[i].dir;
				continue;
			}
			int nextNum = map[ny][nx];
			if (nextNum == 0)
			{
				map[y][x] = 0;
			}
			else {
				fishes[nextNum].x = x;
				fishes[nextNum].y = y;
				map[y][x] = nextNum;
			}
			fishes[i].x = nx;
			fishes[i].y = ny;
			map[ny][nx] = i;
			break;
		}
	}

	int x = shark.x;
	int y = shark.y;
	int dir = shark.dir;

	for (int jump = 1; jump <= 3; ++jump)
	{
		Fish temp[17];

		for (int idx = 0; idx < 17; ++idx)
		{
			temp[idx] = fishes[idx];
		}
		int tempMap[4][4];

		for (int i = 0; i < 4;++i)
		{
			for (int j = 0; j < 4;++j)
			{
				tempMap[i][j] = map[i][j];
			}
		}
		int nx = x + dx[dir] * jump;
		int ny = y + dy[dir] * jump;

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
		{
			continue;
		}
		if (tempMap[ny][nx] == 0)
		{
			continue;
		}
		shark.x = nx;
		shark.y = ny;		

		int score = tempMap[ny][nx];
		tempMap[ny][nx] = 0;
		shark.dir = temp[score].dir;
		temp[score].num = 0;
		simulation(temp, tempMap, shark, total + score);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	Fish shark;
	Fish fishes[17] = { 0 };
	int map[4][4] = { 0 };
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			int num, dir;
			cin >> num >> dir;

			if (x == 0 && y == 0)
			{
				shark.num = num;
				shark.dir = dir;
				shark.x = x;
				shark.y = y;
				continue;
			}
			fishes[num].num = num;
			fishes[num].dir = dir;
			fishes[num].x = x;
			fishes[num].y = y;
			map[y][x] = num;
		}
	}

	simulation(fishes, map, shark, shark.num);

	cout << result << "\n";

	return 0;
}
