// BOJ 2580

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[9][9];
int x, y;
vector<pair<int, int>> v;
void DFS(int x, int y) {
	int arr[9] = { 0 };
	vector<int> vi;
	for (int i = 0; i < 9; ++i)
	{
		if (map[x][i])
			arr[map[x][i] - 1] = 1;
		if (map[i][y])
			arr[map[i][y] - 1] = 1;
	}
	int sub_row = x / 3, sub_col = y / 3;
	sub_row *= 3;  sub_col *= 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (map[sub_row][sub_col + j])   
				arr[map[sub_row][sub_col + j] - 1] = 1;
		}
		++sub_row;
	}
	for (int i = 0; i < 9; ++i) {
		if (!arr[i]) 
			vi.push_back(i + 1);
	}
	if (!vi.size())
		return;
	int next_row = x, next_col = y;
	while (true) {
		if ((++next_col) == 9) {
			next_row++;
			next_col = 0;
			if (next_row == 9) {
				map[x][y] = vi[0];
				for (int i = 0; i < 9; ++i)
				{
					for (int j = 0; j < 9; ++j)
					{
						cout << map[i][j] << " ";
					}
					cout << "\n";
				}
				exit(0);
			}
		}
		if (next_row == 9) 
			break;
		if (map[next_row][next_col] == 0)
			break;
	}
	for (int i = 0; i < vi.size(); ++i) {
		map[x][y] = vi[i];
		DFS(next_row, next_col);
		map[x][y] = 0;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		x = v[i].first;
		y = v[i].second;
		if (map[x][y] == 0)
		{
			DFS(x, y);
		}
	}
}
