#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
char map[25][26];
bool visit[25][25];
int n;
struct pos {
	int x, y;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> v;
	cin >> n;
	for (int y = 0; y < n; ++y) {
		cin >> map[y];
	}
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (map[y][x] == '1' && !visit[y][x])
			{
				pos s = { x,y };
				int _count = 0;
				queue<pos> q;
				q.push(s);
				visit[s.y][s.x] = true;
				while (!q.empty())
				{
					pos cur = q.front();
					q.pop();
					++_count;
					if (cur.x + 1 < n && !visit[cur.y][cur.x + 1] && map[cur.y][cur.x + 1] == '1')
					{
						visit[cur.y][cur.x + 1] = true;
						q.push({ cur.x + 1,cur.y });
					}
					if (cur.y + 1 < n && !visit[cur.y + 1][cur.x] && map[cur.y + 1][cur.x] == '1')
					{
						visit[cur.y + 1][cur.x] = true;
						q.push({ cur.x,cur.y + 1 });
					}
					if (cur.x - 1 >= 0 && !visit[cur.y][cur.x - 1] && map[cur.y][cur.x - 1] == '1')
					{
						visit[cur.y][cur.x - 1] = true;
						q.push({ cur.x - 1,cur.y });
					}
					if (cur.y - 1 >= 0 && !visit[cur.y - 1][cur.x] && map[cur.y - 1][cur.x] == '1')
					{
						visit[cur.y - 1][cur.x] = true;
						q.push({ cur.x,cur.y - 1 });
					}
				}
				v.push_back(_count);
			}
		}
	}
	sort(v.begin(), v.end());
	int len = v.size();
	cout << len << "\n";
	for (int i = 0; i < len; ++i)
	{
		cout << v[i] << "\n";
	}
	return 0;
}
