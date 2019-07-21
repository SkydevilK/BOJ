#include<iostream>
using namespace std;
int note[11];
int main(void)
{
	ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	note[1] = 1;
	note[2] = 2;
	note[3] = 4;
	for (int i = 4; i <= 10; ++i)
	{
		note[i] = note[i - 3] + note[i - 2] + note[i - 1];
	}
	for (int test = 1; test <= T; ++test)
	{
		int N = 0;
		cin >> N;
		cout << note[N] << "\n";
	}
}
