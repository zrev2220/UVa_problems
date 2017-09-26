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

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<char>> grid;
int R, C;

int floodfill(int r, int c, char c1, char c2)
{
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (grid.at(r).at(c) != c1) return 0;
	int ans = 1;
	grid.at(r).at(c) = c2;
	for (int i = 0; i < 8; i++)
		ans += floodfill(r + dr[i], c + dc[i], c1, c2);
	return ans;
}

int main()
{
	while (scanf("%d %d\n", &R, &C) != EOF)
	{
		for (int i = 0 ; i < R; ++i)
		{
			char* line; scanf("%s\n", line);
			grid.push_back(vector<char>(line, line + C));
		}
		int x, y; scanf("%d %d\n\n", &x, &y);
		ii mijid = make_pair(y, x);
		char land = grid.at(y).at(x);
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
