#include<iostream>
#include<cstring>
using namespace std;
int note_zero[41];
int note_one[41];
void dp()
{
	for (int i = 2; i < 41; ++i)
	{
		note_zero[i] = note_zero[i - 2] + note_zero[i - 1];
		note_one[i] = note_one[i - 2] + note_one[i - 1];
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	memset(note_zero, -1, sizeof(note_zero));
	memset(note_one, -1, sizeof(note_one));
	note_zero[0] = 1;
	note_one[0] = 0;
	note_zero[1] = 0;
	note_one[1] = 1;
	dp();
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		int N = 0;
		cin >> N;
		cout << note_zero[N] << " " << note_one[N] << "\n";
	}
}
