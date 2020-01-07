#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
    long long max = -9876543210,temp=0,cur=0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		temp = cur;
		cin >> arr[i];
		temp += arr[i];
		if (temp > max)
		{
			max = temp;
		}
		if (temp > 0)
			cur = temp;
		else
			cur = 0;
	}
	cout << max;
	return 0;
}
