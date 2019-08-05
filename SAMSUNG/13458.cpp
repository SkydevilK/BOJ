#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[N];
	int superNum;
	int subNum;
	long count = 0;
	count = N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	cin >> superNum >> subNum;
	for (int i = 0; i < N; ++i)
	{
		arr[i] -= superNum;
		if (arr[i] > 0)
		{
			count += (arr[i] % subNum == 0) ? (arr[i] / subNum) : ((arr[i] / subNum) + 1);
		}
	}
	cout << count;
