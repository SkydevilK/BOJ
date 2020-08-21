// BOJ 2458

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	fill(&dp[0][0], &dp[n][n + 1], 1e5);

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		bool isCheck = true;
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			if (dp[i][j] == 1e5 && dp[j][i] == 1e5) {
				isCheck = false;
				break;
			}
		}
		if (isCheck)
			ans += 1;
	}
	cout << ans << '\n';
	return 0;
}
