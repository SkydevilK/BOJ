#include<iostream>
using namespace std;
long memo[101][11];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		memo[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		memo[i][0] = memo[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % 1000000000;
		}
	}
	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += memo[n][i];
	}
	cout << sum % 1000000000;
}