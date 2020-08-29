// BOJ 7579
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int memory[101];
int cost[101];
int dp[10001];
int sum;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0, a; i < N; ++i) {
		cin >> memory[i];
	}
	for (int i = 0, b; i < N; ++i) {
		cin >> cost[i];
		sum += cost[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = sum; j >= cost[i]; --j) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}
	int i = 0;
	while (i < sum && dp[i] < M)
	{
		++i;
	}
	cout << i << "\n";
}
