#include <iostream>
#include <cstring>
using namespace std;

int t;
int d[31][31];
int dp(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (d[n][r]) return d[n][r];
	return d[n][r] = dp(n - 1, r - 1) + dp(n - 1, r);
}
int main() {
	cin >> t;
	while (t--) {
		memset(d, 0, sizeof(d));

		int n, m;
		cin >> n >> m;
		cout << dp(m, n) << '\n';
	}
}
