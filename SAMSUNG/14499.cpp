#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dice[6];
void Right()
{
	int temp = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[1];
	dice[1] = temp;
}
void Left()
{
	int temp = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[3];
	dice[3] = temp;
}
void Up()
{
	int temp = dice[2];
	dice[2] = dice[0];
	dice[0] = dice[5];
	dice[5] = dice[4];
	dice[4] = temp;
}
void Down()
{
	int temp = dice[2];
	dice[2] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[0];
	dice[0] = temp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	int** map = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		map[i] = new int[M];
		memset(map[i], 0, sizeof(map));
	}
	for (int _x = 0; _x < N; ++_x)
	{
		for (int _y = 0; _y < M; ++_y)
		{
			cin >> map[_x][_y];
		}
	}
	queue<int> q;
	for (int i = 0; i < K; ++i)
	{
		int temp = 0;
		cin >> temp;
		q.push(temp);
	}
	if (map[x][y] != 0)
	{
		dice[2] = map[x][y];
	}
	while (!q.empty())
	{
		int order = q.front();
		q.pop();
		switch (order)
		{
			case 1:
				++y;
				if (y < M)
				{
					Right();
					cout << dice[5] << "\n";
					if (map[x][y] != 0)
					{
						dice[2] = map[x][y];
						map[x][y] = 0;
					}
					else
					{
						map[x][y] = dice[2];
					}
				}
				else
				{
					--y;
				}
			break;
			case 2:
				--y;
				if (y >= 0)
				{
					Left();
					cout << dice[5] << "\n";
					if (map[x][y] != 0)
					{
						dice[2] = map[x][y];
						map[x][y] = 0;
					}
					else
					{
						map[x][y] = dice[2];
					}
				}
				else
				{
					++y;
				}
				break;
			case 3:
				--x;
				if (x >= 0)
				{
					Up();
					cout << dice[5] << "\n";
					if (map[x][y] != 0)
					{
						dice[2] = map[x][y];
						map[x][y] = 0;
					}
					else
					{
						map[x][y] = dice[2];
					}
				}
				else
				{
					++x;
				}
				break;
			case 4:
				++x;
				if (x < N)
				{
					Down();
					cout << dice[5] << "\n";
					if (map[x][y] != 0)
					{
						dice[2] = map[x][y];
						map[x][y] = 0;
					}
					else
					{
						map[x][y] = dice[2];
					}
				}
				else
				{
					--x;
				}
				break;
		}
	}
}
