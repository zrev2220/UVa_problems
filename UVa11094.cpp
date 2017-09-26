#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
vector<vector<char>> grid;
int R, C;

int floodfill(int r, int c, char c1, char c2)
{
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (grid.at(r).at(c) != c1) return 0;
	int ans = 1;
	grid.at(r).at(c) = c2;
	for (int i = 0; i < 4; i++)
	{
		int toR = r + dr[i];
		int toC = (C + c + dc[i]) % C;
		ans += floodfill(toR, toC, c1, c2);
	}
	return ans;
}

int main()
{
	while (scanf("%d %d\n", &R, &C) != EOF)
	{
		// printf("%d %d\n", R, C);
		grid.clear();
		for (int i = 0 ; i < R; ++i)
		{
			char* line = new char[C]; scanf("%s\n", line);
			// printf("%s\n", line);
			grid.push_back(vector<char>(line, line + C));
			delete[] line;
		}
		int x, y; scanf("%d %d\n\n", &x, &y);
		// printf("%d %d\n", x, y);
		char land = grid.at(x).at(y);
		floodfill(x, y, land, '\0');
		int largest = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				char c = grid.at(i).at(j);
				if (c == land)
					largest = max(largest, floodfill(i, j, land, '\0'));
			}
		}
		printf("%d\n", largest);
	}
	return 0;
}
