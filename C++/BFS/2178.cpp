#include <iostream>
#include<queue>
using namespace std;
char map[100][101];
bool visit[100][100];
struct pos {
	int x, y;
	int count;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, result = 0;
	cin >> n >> m;
	for (int y = 0; y < n; ++y) {
		cin >> map[y];
	}
	pos s = { 0,0,1 };
	queue<pos> q;
	q.push(s);
	visit[s.y][s.x] = true;

	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();
		if (cur.x  == m-1 && cur.y  == n-1)
		{
			result = cur.count;
			break;
		}
		if (cur.x + 1 < m && !visit[cur.y][cur.x + 1] && map[cur.y][cur.x + 1] == '1')
		{
			visit[cur.y][cur.x + 1] = true;
			q.push({ cur.x + 1,cur.y,cur.count + 1 });
		}
		if (cur.y + 1 < n && !visit[cur.y + 1][cur.x] && map[cur.y + 1][cur.x] == '1')
		{
			visit[cur.y + 1][cur.x] = true;
			q.push({ cur.x,cur.y + 1,cur.count + 1 });
		}
		if (cur.x - 1 >= 0 && !visit[cur.y][cur.x - 1] && map[cur.y][cur.x - 1] == '1')
		{
			visit[cur.y][cur.x - 1] = true;
			q.push({ cur.x - 1,cur.y,cur.count + 1 });
		}
		if (cur.y - 1 >= 0 && !visit[cur.y - 1][cur.x] && map[cur.y - 1][cur.x] == '1')
		{
			visit[cur.y - 1][cur.x] = true;
			q.push({ cur.x,cur.y - 1,cur.count + 1 });
		}
	}
	cout << result << "\n";
	return 0;
}
