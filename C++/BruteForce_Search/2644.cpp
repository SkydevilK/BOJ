#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int n, m;
int num1, num2;
int x, y;
int depth[101];
int map[101][101];
bool visit[101];
queue <int> q;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> num1 >> num2;
	cin >> m;
	int a, b;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	visit[num1] = true;
	q.push(num1);
	int temp;
	while (!q.empty())
	{
		temp = q.front(); q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (map[temp][i] == 1 && !visit[i])
			{
				visit[i] = true;
				depth[i] = depth[temp] + 1;
				q.push(i);
			}
		}
	}
	if (depth[num2] != 0)
		cout << depth[num2] << "\n";
	else
		cout << "-1\n";
	return 0;
}
