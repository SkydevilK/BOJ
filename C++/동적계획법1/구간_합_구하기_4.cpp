// BOJ 11658.cpp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M,i,j;
	cin >> N >> M;
	int* total = new int[N + 1];
	total[0] = 0;
	int* arr = new int[N + 1];
	for(int i=1;i<=N;++i)
	{
		cin >> arr[i];
		total[i] = total[i - 1] + arr[i];
	}
	while (M--)
	{
		cin >> i >> j;
		cout << total[j] - total[i-1] << "\n";
	}
	return 0;
}
