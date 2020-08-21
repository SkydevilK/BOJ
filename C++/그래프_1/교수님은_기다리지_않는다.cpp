// BOJ 3830

#include <iostream>
using namespace std;

int N, M, p[100001];
long long dist[100001];
int Find(int x) {
	if (p[x] == x) return x;
	int temp = Find(p[x]);
	dist[x] += dist[p[x]];
	return p[x] = temp;
}
void Union(int a, int b, int diff) {
	int A = p[a];
	int B = p[b];
	if (A == B) return;
	int NewD = dist[a] + diff;
	int OriginD = dist[b];
	p[B] = A;
	dist[B] = NewD - OriginD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		for (int i = 1; i <= N; ++i) {
			p[i] = i;
			dist[i] = 0;
		}
		for (int i = 0; i < M; ++i) {
			char c;
			int a, b, w;
			cin >> c >> a >> b;
			Find(a);
			Find(b);
			if (c == '!') {
				cin >> w;
				Union(a, b, w);
			}
			else {
				if (p[a] == p[b])
					cout << dist[b] - dist[a] << '\n';
				else 
					cout << "UNKNOWN" << '\n';
			}
		}
	}
	return 0;
}
