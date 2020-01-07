#include <iostream>
#include <algorithm>
using namespace std;
int note[1001];
int dp(int n)
{
	if (note[n] != 0)
		return note[n];
	return note[n] = (dp(n - 1) + dp(n - 2))%10007;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int  N;
	note[1] = 1;
	note[2] = 2;
	note[3] = 3;
	cin >> N;
	cout << dp(N);
	return 0;
}
