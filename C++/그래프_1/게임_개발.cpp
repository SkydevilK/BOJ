// BOJ 1516

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int degree[501];
int duration[501];
int result[501];
vector<int> graph[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int time;
		cin >> time;
		duration[i] = time;
		while (true)
		{
			int node;
			cin >> node;

			if (node == -1)
			{
				break;
			}
			++degree[i];
			graph[node].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); ++i)
		{
			int nextNode = graph[node][i];
			result[nextNode] = max(result[nextNode], result[node] + duration[node]);
			if (--degree[nextNode] == 0)
			{
				q.push(nextNode);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		cout << result[i] + duration[i] << "\n";
	}
	return 0;
}
