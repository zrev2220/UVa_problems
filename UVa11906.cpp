#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

#define UNVISITED -1
#define VISITED 1

vi dfs_num;
int r, c, m, n, w;
bitset<10000> water;
int evens, odds;
const unordered_map<int, ii> dir {
	{0, make_pair(1, 1)},
	{1, make_pair(-1, -1)},
	{2, make_pair(1, -1)},
	{3, make_pair(-1, 1)}
};

int pair2idx(ii p)
{
	return p.second * c + p.first;
}

ii idx2pair(int i)
{
	return make_pair(i % c, i / c);
}

bool pairOnMap(ii p)
{
	return p.first >= 0 && p.first < c && p.second >= 0 && p.second < r;
}

void dfs(int u)
{
	dfs_num.at(u) = VISITED;
	vi goNext;
	for (int i = 0; i < 4; i++)
	{
		ii cell = idx2pair(u);
		ii moveTo = make_pair(cell.first + dir.at(i).first * m, cell.second + dir.at(i).second * n);
		if (pairOnMap(moveTo) && !water.test(pair2idx(moveTo)))
			goNext.push_back(pair2idx(moveTo));
		if (m != n)
		{
			moveTo = make_pair(cell.first + dir.at(i).first * n, cell.second + dir.at(i).second * m);
			if (pairOnMap(moveTo) && !water.test(pair2idx(moveTo)))
				goNext.push_back(pair2idx(moveTo));
		}
		// corner cases, quit early
		if ((m == 0 || n == 0) && i >= 1)
			break;
	}
	if ((int) goNext.size() % 2 == 0)
		evens++;
	else if ((int) goNext.size() % 2 == 1)
		odds++;
	for (int j = 0; j < (int) goNext.size(); j++)
	{
		int v = goNext.at(j);
		if (dfs_num.at(v) == UNVISITED)
			dfs(v);
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int caseNo = 1; caseNo <= t; caseNo++)
	{
		scanf("%d %d %d %d\n%d", &r, &c, &m, &n, &w);
		dfs_num.assign(r * c, UNVISITED);
		evens = odds = 0;
		water.reset();
		while (w--)
		{
			int x, y; scanf("%d %d", &x, &y);
			water.set(pair2idx(make_pair(y, x)));
		}
		dfs(0);
		printf("Case %d: %d %d\n", caseNo, evens, odds);
	}
	return 0;
}
