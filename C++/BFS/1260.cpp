#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int adj[1001][1001];
bool visit[1001];
int N, M, V;
queue<int> q;
void dfs(int idx)
{
	cout << idx << " ";
	for (int i = 1; i <= N; ++i)
	{
		if (adj[idx][i] && !visit[i])
		{
			visit[i] = 1;
			dfs(i);
		}
	}
}
void bfs(int idx)
{
	q.push(idx);
	visit[idx] = 1;
	while (!q.empty())
	{
		idx = q.front();
	    cout << idx << " ";
		q.pop();
		for (int i = 1; i <= N; i++)

			if (adj[idx][i] && !visit[i])
			{
				visit[i] = 1;
				q.push(i);
			}
	}
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}
	visit[V] = 1;
	dfs(V);
	cout << "\n";
    memset(visit, false, sizeof(visit));
	bfs(V);
	cout << "\n";
}
