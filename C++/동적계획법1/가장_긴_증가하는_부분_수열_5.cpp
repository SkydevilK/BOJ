// BOJ 14003

#include <iostream>
#include <stack>

using namespace std;
struct LIS {
    int position;
    int value;
};
int arr[1000001];
int lis[1000001];
LIS ans[1000001];
stack<int> s;

int find(int start, int end, int target)
{
    int mid;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (lis[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int pLis = 0, pArr = 1;
    lis[pLis] = arr[0];
    ans[0].position = 0;
    ans[0].value = arr[0];
    while (pArr < N)
    {
        if (lis[pLis] < arr[pArr])
        {
            lis[++pLis] = arr[pArr];
            ans[pArr].position = pLis;
            ans[pArr].value = arr[pArr];
        }
        else
        {
            int pos = find(0, pLis, arr[pArr]);
            lis[pos - 1] = arr[pArr];
            ans[pArr].position = pos - 1;
            ans[pArr].value = arr[pArr];
        }
        ++pArr;
    }
    cout << pLis + 1 << "\n";
    int t = pLis;

    for (int i = N - 1; i >= 0; --i)
    {
        if (ans[i].position == t)
        {
            s.push(ans[i].value);
            --t;
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
