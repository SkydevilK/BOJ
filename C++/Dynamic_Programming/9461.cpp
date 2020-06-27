#include <iostream>
#include <algorithm>
using namespace std;
int N = 0;
long long note[101] = { 0,1,1,1 };
long long dp(int n)
{
	if (note[n] != 0)
		return note[n];
	return note[n] = dp(n - 3) + dp(n - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp(100);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cin >> N;
		cout << dp(N) << "\n";
	}
	return 0;
}
