#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, A[1001]{ 0 }, dp[1001]{ 0 }, max = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
	return 0;
}
