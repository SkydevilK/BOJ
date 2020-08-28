// BOJ 11049

#include <iostream>
using namespace std;
int mat[501][2];
int memo[501][501];
int dp(int x, int y)
{
	if (memo[x][y]) return memo[x][y];
	if (x == y) return 0;
	if (x + 1 == y) return mat[x][0] * mat[x][1] * mat[y][1];
	int& ret = memo[x][y];
	ret = -1;
	for (int i = x; i < y; ++i)
	{
		int t1 = dp(x, i);
		int t2 = dp(i + 1, y);
		if (ret == -1 || ret > t1 + t2 + mat[x][0] * mat[i][1] * mat[y][1])
			ret = t1 + t2 + mat[x][0] * mat[i][1] * mat[y][1];
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, r, c;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> r >> c, mat[i][0] = r, mat[i][1] = c;
	cout << dp(0, N - 1) << "\n";
	return 0;
}
