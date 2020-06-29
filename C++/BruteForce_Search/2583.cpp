#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 
bool range[101][101];
bool visited[101][101]; 
int M, N, K; 
void DFS(int y, int x, int &area)
{
	visited[y][x] = true; area++; 
	vector<pair<int, int> > wsad; 
	wsad.push_back({-1, 0}); 
	wsad.push_back({+1, 0});
	wsad.push_back({0, -1});
	wsad.push_back({0, +1});
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + wsad[i].first;
		int nextX = x + wsad[i].second; 
		bool yCheck = (nextY >= 0) && (nextY < M);
		bool xCheck = (nextX >= 0) && (nextX < N); 
		if (yCheck && xCheck)
		{
			if (!range[nextY][nextX] && !visited[nextY][nextX]) 
				DFS(nextY, nextX, area); 
		}
	} 
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v; 
	cin >> M >> N >> K;
	while (K--) 
	{
		int x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2; 
		for (int i = y1; i < y2; i++) 
		{
			for (int j = x1; j < x2; j++) 
			{
				range[i][j] = true;
			}
		}
	}
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
		 if (!range[i][j] && !visited[i][j])
		 { 
			 int t = 0; DFS(i, j, t); 
			 v.push_back(t); 
		 }
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n'; 
	for (auto i : v) { cout << i << " "; 
	}
}
