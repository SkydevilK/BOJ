#include <iostream>
using namespace std;
int note[90];
int dp(int n)
{
	if (note[n] != 0)
		return note[n];
	return note[n] = dp(n - 1) + dp(n - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin >> N;
	note[0] = 1;
	note[1] = 1;
	cout << dp(N - 1);
	return 0;
}
