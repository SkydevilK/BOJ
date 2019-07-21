#include<iostream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	int N;
	int min = 0;
	cin >> N;
	int* dp = new int[N + 1];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; ++i)
	{
		min = dp[i - 1] + 1;
		if (i % 2 == 0) min = min < (dp[i / 2] + 1) ? min : dp[i / 2] + 1;
		if (i % 3 == 0)  min = min < (dp[i / 3] + 1) ? min : dp[i / 3] + 1;

		dp[i] = min;
	}
	cout << dp[N] << "\n";
}
