// BOJ 2252
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> graph[32001];
int degree[32001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		++degree[b];
		graph[a].push_back(b);
	}
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		ans.push_back(p);

		for (int k = 0; k < graph[p].size(); ++k) {
			int y = graph[p][k];
			if (--degree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
