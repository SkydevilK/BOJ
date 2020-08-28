// BOJ 1932

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, result = 0;
	cin >> N;
	vector<vector<int> > arr(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> arr[i][j];
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			if (i == N) {
				result = max(result, arr[i][j]);
			}
		}
	}
	cout << result;
	return 0;
}
