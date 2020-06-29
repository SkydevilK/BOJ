#include <iostream>
#include <queue> 
using namespace std;
bool map[1001][1001];
bool visit[1001];
int main()
{
	int N, M, count = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = map[y][x] = true;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i])
			continue;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			if (visit[cur])
				continue;
			visit[cur] = true;
			for (int j = 1; j <= N; j++)
			{
				if (map[cur][j])
					q.push(j);
			}
		}
		count++;
	}
	cout << count;
	return 0;
}
