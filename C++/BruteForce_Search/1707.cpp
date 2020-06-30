#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int K, V, E;
int s, e;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> V >> E;
        vector<vector<int>> v(V+1);
		for (int j = 0; j < E; ++j)
		{
			cin >> s >> e;
			v[s].push_back(e);
			v[e].push_back(s);
		}
        int len = v.size();
        int* color = new int[len];
        memset(color, 0, sizeof(int)*len);
        queue<int> q;

        for (int j = 0; j < len; ++j) {
            if (color[j] != 0) continue;
            q.push(j);

            while (!q.empty()) {
                int qLen = q.size();
                for (int k = 0; k < qLen; ++k) {
                    int cur = q.front();
                    q.pop();

                    int tempColor = 0;
                    for (int next : v[cur]) {
                        if (color[next] == 0) 
                            q.push(next);
                        else {
                            if (tempColor == 0)
                                tempColor = color[next];
                            else if (tempColor != color[next])
                                goto loopJump;
                        }
                    }
                    if (tempColor == 0)                    {
                        color[cur] = 1;
                    }
                    else {
                        color[cur] = 3 - tempColor;
                    }
                }
            }
        }
        cout << "YES\n";
        continue;
    loopJump:
        cout << "NO\n";
	}
  

	return 0;
}
