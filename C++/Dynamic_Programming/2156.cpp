#include <iostream>
#include <algorithm>
using namespace std;
int dp(int* wine, int* note, int n) {
	if (n < 1) {
		return 0;
	}
	else if (n == 1) {
		return wine[1];
	}
	else if (n == 2) {
		return wine[1] + wine[2];
	}
	if (note[n] > 0) {
		return note[n];
	}
	note[n] = max(max(dp(wine, note, n - 1), dp(wine, note, n - 2) + wine[n]), dp(wine, note, n - 3) + wine[n] + wine[n - 1]);
	return note[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int* wine;
	int* note;
	cin >> N;
	wine = new int[N + 1];
	note = new int[N + 1];
	for (int i = 1; i <= N; ++i) {
		cin >> wine[i];
	}
	cout << dp(wine, note, N);
	return 0;
}
