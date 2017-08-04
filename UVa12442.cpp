// Correct answer, but gets TLE
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
bitset<500000> dfs_bit;
vi adjList;
vi cycleLength;

int dfs(int u)
{
	if (cycleLength.at(u) != -1)
		return cycleLength.at(u);
	int size = 1;
	dfs_num.at(u) = VISITED;
	dfs_bit.set(u);
	int v = adjList.at(u);
	while (dfs_num.at(v) == UNVISITED)
	{
		size++;
		dfs_num.at(v) = VISITED;
		dfs_bit.set(v);
		v = adjList.at(v);
	}
	// set cycleLength of all v's in cycle
	int k = v;
	if (k == u)
	{
		do
		{
			cycleLength.at(v) = size;
			v = adjList.at(v);
		}
		while (v != k);
	}
	else
	{
		int l = 1;
		v = adjList.at(k);
		do
		{
			l++;
			v = adjList.at(v);
		} while (v != k);
		do
		{
			cycleLength.at(v) = l;
			v = adjList.at(v);
		}
		while (v != k);
		v = u;
		for (int i = 0; v != k; i++)
		{
			cycleLength.at(v) = size - i;
			v = adjList.at(v);
		}
	}
	return size;
}

int main()
{
	int t; scanf("%d", &t);
	for (int caseNo = 1; caseNo <= t; caseNo++)
	{
		int n; scanf("%d", &n);
		dfs_num.assign(n, UNVISITED);
		dfs_bit.reset();
		adjList.assign(n, -1);
		cycleLength.assign(n, -1);
		ii bestMartian = make_pair(-1, -1);
		// first = size; second = vertex
		for (int i = 0; i < n; i++)
		{
			int u, v; scanf("%d %d", &u, &v);
			adjList.at(u - 1) = v - 1;
		}
		for (int u = 0; u < n; u++)
		{
			if (!dfs_bit.test(u))
			{
				int newSize = dfs(u);
				if (newSize > bestMartian.first)
					bestMartian = make_pair(newSize, u);
				else if (newSize == bestMartian.first)
					bestMartian.second = min(bestMartian.second, u);
				dfs_num.assign(n, UNVISITED);
			}
		}
		// for (int i = 0; i < n; i++)
			// printf("## %d:%d\n", i, cycleLength.at(i));
		printf("Case %d: %d\n", caseNo, bestMartian.second + 1);
	}
	return 0;
}
