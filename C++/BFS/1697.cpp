#include <iostream>
#include<queue>
using namespace std;
int visit[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	visit[N] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == K)
		{
			cout << visit[cur] - 1;
			break;
		}
		else {
			if (cur - 1 >= 0 && visit[cur - 1] == 0)
			{
				visit[cur - 1] = visit[cur] + 1;
				q.push(cur - 1);
			}
			if (cur + 1 < 100001 && visit[cur + 1] == 0)
			{
				visit[cur + 1] = visit[cur] + 1;
				q.push(cur + 1);
			}
			if (cur * 2 < 100001 && visit[cur * 2] == 0)
			{
				visit[cur * 2] = visit[cur] + 1;
				q.push(cur * 2);
			}
		}
	}
	return 0;
}
