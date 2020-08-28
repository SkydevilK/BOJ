// BOJ 1915

#include<iostream>
#include<algorithm>
using namespace std;
char map[1000][1000];
int memo[1001][1001];
int n, m;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> map[i];
	int row = 0;
	for (int i = 0; i < m; ++i)
		memo[0][i] = map[0][i] - '0';

	for (int i = 1; i < n; ++i) {
		memo[i][0] = map[i][0] - '0';
		for (int j = 1; j < m; ++j)
			memo[i][j] = (map[i][j] - '0') * (
				min(min(memo[i][j - 1], memo[i - 1][j]), memo[i - 1][j - 1]) + 1);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			row = max(row, memo[i][j]);
	}
	cout << row * row;
}
