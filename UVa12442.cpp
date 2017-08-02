// Correct answer, but gets TLE
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

#define UNVISITED -1
#define VISITED 1
#define EXPLORED 2

vi dfs_num;
vector<vi> adjList;
unordered_map<int, int> cycleLength; // unused right now

int dfs(int u)
{
	int size = 1;
	dfs_num.at(u) = EXPLORED;
	for (int j = 0; j < (int) adjList.at(u).size(); j++)
	{
		int v = adjList.at(u).at(j);
		if (dfs_num.at(v) == UNVISITED)
		{
			size += dfs(v);
		}
		else if (dfs_num.at(v) == EXPLORED)
		{
			// cycle check of some kind
		}
	}
	dfs_num.at(u) = VISITED;
	return size;
}

int main()
{
	int t; scanf("%d", &t);
	for (int caseNo = 1; caseNo <= t; caseNo++)
	{
		int n; scanf("%d", &n);
		dfs_num.assign(n, UNVISITED);
		adjList.assign(n, vi(0));
		cycleLength.clear();
		ii bestMartian = make_pair(-1, -1);
		// first = size; second = vertex
		for (int i = 0; i < n; i++)
		{
			int u, v; scanf("%d %d", &u, &v);
			adjList.at(u - 1).push_back(v - 1);
			cycleLength[i] = 0;
		}
		for (int u = 0; u < n; u++)
		{
			int newSize = dfs(u);
			if (newSize > bestMartian.first)
				bestMartian = make_pair(newSize, u);
			else if (newSize == bestMartian.first)
				bestMartian.second = min(bestMartian.second, u);
			dfs_num.assign(n, UNVISITED);
		}
		printf("Case %d: %d\n", caseNo, bestMartian.second + 1);
	}
	return 0;
}
