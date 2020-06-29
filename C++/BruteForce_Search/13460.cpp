#include <iostream>
#include<queue>
using namespace std;
int N, M;
char map[10][10];
bool visit[10][10][10][10];
struct INFO
{
	int bx,by,rx,ry,count;
};
INFO START;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
		{
			cin >> map[y][x];
			if (map[y][x] == 'R')
			{
				START.rx = x;
				START.ry = y;
			}
			else if (map[y][x] == 'B')
			{
				START.bx = x;
				START.by = y;
			}
		}
	queue<INFO> q;
	visit[START.rx][START.ry][START.bx][START.by] = true;
	q.push(START);
	int result = -1;
	while (!q.empty())
	{
		INFO cur = q.front();
		q.pop();
		if (cur.count > 10)
			break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
		{
			result = cur.count;
			break;
		}for (int dir = 0; dir < 4; ++dir)
		{
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;
			while (true)
			{
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
				{
					next_rx += dx[dir];
					next_ry += dy[dir];
				}
				else
				{
					if (map[next_ry][next_rx] == '#')
					{
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
					break;
				}
			}
			while (true)
			{
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
				{
					next_bx += dx[dir];
					next_by += dy[dir];
				}
				else
				{
					if (map[next_by][next_bx] == '#')
					{
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
					break;
				}
			}

			if (next_bx == next_rx && next_by == next_ry)
			{
				if (map[next_ry][next_rx] != 'O')
				{
					int red_dis = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
					int blue_dis = abs(next_bx - cur.bx) + abs(next_by - cur.by);
					if (red_dis > blue_dis)
					{
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
					else
					{
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
				}
			}
			if (visit[next_rx][next_ry][next_bx][next_by] == false)
			{
				visit[next_rx][next_ry][next_bx][next_by] = true;
				INFO NEXT;
				NEXT.bx = next_bx;
				NEXT.by = next_by;
				NEXT.rx = next_rx;
				NEXT.ry = next_ry;
				NEXT.count = 1 + cur.count;
				q.push(NEXT);
			}
		}
	}
	cout << result;
}
