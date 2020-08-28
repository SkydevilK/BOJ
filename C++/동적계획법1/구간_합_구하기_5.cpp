// BOJ 11660

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int RowSum[1025][1025];
int map[1025][1025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, sum;
	int x1, x2, y1, y2;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
			RowSum[i][j] = RowSum[i][j - 1] + map[i][j];
		}
	}
	while (M--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		sum = 0;
		for (int i = x1; i <= x2; ++i)
		{
			sum += RowSum[i][y2] - RowSum[i][y1 - 1];
		}
		cout << sum << "\n";
	}
	return 0;
}
