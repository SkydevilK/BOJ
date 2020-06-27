#include<iostream>
#include<queue>
using namespace std;
int T[15];
int P[15];
int note[15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		note[i] = P[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				note[i] = max(note[j] + P[i], note[i]);
			}
		}
	}
	int _max = 0;
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			if (_max < note[i]) {
				_max = note[i];
			}
		}
	}
	cout << _max;
}
