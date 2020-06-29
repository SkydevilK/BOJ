#include <iostream>
#include<queue>
using namespace std;
struct pos
{
	int x, y, count;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, l, sx, sy, ex, ey, _count=0;
	cin >> t;
	while (t--)
	{
		cin >> l;
		cin >> sx >> sy;
		cin >> ex >> ey;
		bool visit[301][301] = { false };
		queue<pos> q;
		q.push({ sx,sy,0 });
		visit[sx][sy] = true;
		while (!q.empty())
		{
			pos cur = q.front();
			q.pop();
			if (cur.x == ex && cur.y == ey)
			{
				_count = cur.count;
				break;
			}
			if (cur.x + 2 < l && cur.y + 1 < l && !visit[cur.x + 2][cur.y + 1])
			{
				q.push({ cur.x + 2,cur.y + 1,cur.count + 1 });
				visit[cur.x + 2][cur.y + 1] = true;
			}
			if (cur.x + 1 < l && cur.y + 2 < l && !visit[cur.x + 1][cur.y + 2])
			{
				q.push({ cur.x + 1,cur.y + 2,cur.count + 1 });
				visit[cur.x + 1][cur.y + 2] = true;
			}
			if (cur.x - 2 >= 0 && cur.y + 1 < l && !visit[cur.x - 2][cur.y + 1]) {
				visit[cur.x - 2][cur.y + 1] = true;
				q.push({ cur.x - 2,cur.y + 1,cur.count + 1 });
			}if (cur.x - 1 >= 0 && cur.y + 2 < l && !visit[cur.x - 1][cur.y + 2])
			{
				q.push({ cur.x - 1,cur.y + 2,cur.count + 1 });
				visit[cur.x - 1][cur.y + 2] = true;
			}
			if (cur.x + 2 < l && cur.y - 1 >= 0 && !visit[cur.x + 2][cur.y - 1])
			{
				q.push({ cur.x + 2,cur.y - 1,cur.count + 1 });
				visit[cur.x + 2][cur.y - 1] = true;
			}
			if (cur.x + 1 < l && cur.y - 2 >= 0 && !visit[cur.x + 1][cur.y - 2])
			{
				q.push({ cur.x + 1,cur.y - 2 ,cur.count + 1 });
				visit[cur.x + 1][cur.y - 2] = true;
			}
			if (cur.x - 2 >= 0 && cur.y - 1 >= 0 && !visit[cur.x - 2][cur.y - 1])
			{
				q.push({ cur.x - 2,cur.y - 1,cur.count + 1 });
				visit[cur.x - 2][cur.y - 1] = true;
			}
			if (cur.x - 1 >= 0 && cur.y - 2 >= 0 && !visit[cur.x - 1][cur.y - 2])
			{
				q.push({ cur.x - 1,cur.y - 2,cur.count + 1 });
				visit[cur.x - 1][cur.y - 2] = true;
			}
		}
		cout << _count << "\n";
	}
	return 0;
}
