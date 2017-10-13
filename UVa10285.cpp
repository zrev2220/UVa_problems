#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string name; cin >> name;
		int r, c; cin >> r >> c;
		vector<vi> grid(r, vi(c, 0));
		priority_queue<pair<int, ii>, vector<pair<int, ii>>, less<pair<int, ii>>> cells;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				int h; cin >> h;
				grid.at(i).at(j) = h;
				cells.push(make_pair(h, ii(i, j)));
			}
		}
		vector<vi> memo(r, vi(c, 0));
		int maxrun = 0;
		while (!cells.empty())
		{
			pair<int, ii> curr = cells.top(); cells.pop();
			int curmax = 0;
			for (int d = 0; d < 4; ++d)
			{
				int _r = curr.second.first + dr[d];
				int _c = curr.second.second + dc[d];
				if (_r >= 0 && _r < r && _c >= 0 && _c < c &&
					grid.at(_r).at(_c) > curr.first)
					curmax = max(curmax, memo.at(_r).at(_c));
			}
			maxrun = max(maxrun, curmax + 1);
			memo.at(curr.second.first).at(curr.second.second) = curmax + 1;
		}
		cout << name << ": " << maxrun << endl;
	}
	return 0;
}
