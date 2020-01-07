#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, score[300]{ 0 }, dp[300]{ 0 };
	cin >> N;
	for (register int idx = 0; idx < N; ++idx) {
		cin >> score[idx];
	}
	for (register int idx = 0; idx < N; ++idx) {
		int case1 = score[idx], case2 = score[idx];
		if (idx - 1 >= 0) {
			case1 += dp[idx - 2];
			case2 += score[idx - 1];
			if (idx - 3 >= 0)
				case2 += dp[idx - 3];
		}
		dp[idx] = max(case1, case2);
	}
	cout << dp[N - 1];
	return 0;
}
