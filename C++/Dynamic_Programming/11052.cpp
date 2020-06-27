#include <iostream>
#include <algorithm>
using namespace std;
int N = 0;
int P[1001], dp[1001],answer;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> P[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
		answer = answer > dp[i] ? answer : dp[i];
	}
	cout << answer;
	return 0;
}
