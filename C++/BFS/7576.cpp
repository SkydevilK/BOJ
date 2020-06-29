#include <iostream>
#include<queue>
using namespace std;
int map[1000][1000];
int note[1000][1000];
int M, N, _count = 0;

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
struct pos
{
	int x, y;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	bool isupdate = true;
	queue<pair<int, int> > q;
	cin >> M >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> map[y][x];
			note[y][x] = -1;
			if (map[y][x] == 1)
			{
				q.push({ x, y });
				note[y][x] = 0;

			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i]; 
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (map[ny][nx] == 0 && note[ny][nx] == -1) {
					note[ny][nx] = note[y][x] + 1;
					q.push({ nx, ny });
				}
			}
		}
	} 
	int result = 0;
	for (int y = 0; y < N; ++y) 
	{
		for (int x = 0; x < M; ++x) 
		{
			result = max(result, note[y][x]); 
		}
	}
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (map[y][x] == 0 && note[y][x] == -1)
			{
				result = -1;
			}
		} 
	}
	cout << result;
}
