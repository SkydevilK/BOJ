// BOJ 1103

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, M;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };
int memo[50][50];
char board[50][50];
bool visit[50][50];
int dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return 0;
    if (board[x][y] == 'H')
        return 0;
    if (visit[x][y]) {
        cout << "-1";
        exit(0);
    }
    int& ret = memo[x][y];
    if (ret != -1) 
        return ret;
    visit[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + (board[x][y] - '0') * dx[i];
        int ny = y + (board[x][y] - '0') * dy[i];

        int val = dfs(nx, ny) + 1;
        ret = max(ret, val);
    }
    visit[x][y] = false;
    return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
    string s;
	for (int i = 0; i < N; ++i)
	{
        cin >> s;
		for (int j = 0; j < M; ++j)
		{
            board[i][j] = s[j];
		}
	}
    memset(memo, -1, sizeof(memo));
    cout << dfs(0, 0);
    return 0;
}
