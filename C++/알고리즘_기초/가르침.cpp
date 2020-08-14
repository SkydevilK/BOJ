// BOJ 1062
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool check[26];
vector<string> v;
int answer;
void DFS(int begin, int cnt)
{
    if (cnt == 0) {
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            bool check2 = true;
            for (int j = 0; j < v[i].size(); ++j) {
                int temp = v[i][j] - 'a';
                if (check[temp] == 0) {
                    check2 = false;
                    break;
                }
            }
            if (check2)
                ++sum;
        }
        answer = max(answer, sum);
        return;
    }
    for (int i = begin + 1; i < 26; ++i) {
        if (check[i])
            continue;
        check[i] = true;
        DFS(i, cnt - 1);
        check[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    }
    k -= 5;
    check['a' - 'a'] = true;
    check['n' - 'a'] = true;
    check['t' - 'a'] = true;
    check['i' - 'a'] = true;
    check['c' - 'a'] = true;
    DFS(-1, k);
    cout << answer << "\n";
    return 0;
}
