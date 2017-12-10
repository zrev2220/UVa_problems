#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

map<ii, ii> p;
ii s, t;

string printBin(int x)
{
	string result = "";
	for (int j = 0; j < 11; ++j)
		result += ((x & (1 << j)) ? "1" : "0");
	return result;
}

int LSOneIdx(int x)
{
	for (int i = 0; i < 32; ++i)
	{
		if (x & (1 << i))
			return i;
	}
	return -1;
}

void printTransition(ii u, ii v)
{
	if (u.first == v.first)
	{
		// same room, therefore flipped switch
		// if u's bitmask is greater, light turned OFF ---> |
		// else light turned ON                            \|/
		printf("- Switch %s light in room %d.\n", (u.second > v.second) ? "off" : "on", LSOneIdx(u.second ^ v.second));
	}
	else
	{
		// moved room
		printf("- Move to room %d.\n", v.first);
	}
}

void printPath(ii u, ii v) {
	if (u == v)
	{
		// first call
		printPath(p[u], u);
		return;
	}
	if (u == s)
	{
		printTransition(u, v);
		return;
	}
	printPath(p[u], u);
	printTransition(u, v);
}

int main()
{
	int R, D, S; cin >> R >> D >> S;
	int caseno = 0;
	while (!(R == 0 && D == 0 && S == 0))
	{
		if (D == 0) // corner case
		{
			for (int i = 0; i < S; ++i)
			{
				int u, v; cin >> u >> v;
			}
			printf("Villa #%d\n", ++caseno);
			if (R == 1)
				printf("The problem can be solved in 0 steps:\n\n");
			else
				printf("The problem cannot be solved.\n\n");
			cin >> R >> D >> S;
			continue;
		}
		vector<vi> AdjList(R + 1, vi(0));
		map<int, vi> SwitchList;
		for (int i = 0; i < D; ++i)
		{
			int u, v; cin >> u >> v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		for (int i = 0; i < S; ++i)
		{
			int u, v; cin >> u >> v;
			SwitchList[u].push_back(v);
		}
		// BFS routine
		s = {1, 2};
		t = {R, 1 << R};
		map<ii, int> dist; dist[s] = 0;
		queue<ii> q; q.push(s);
		int layer = -1;

		while (!q.empty()) {
			ii u = q.front(); q.pop();
			layer = dist[u];
			// from this state, can flip a switch or move to another room
			// explore: move room
			for (int j = 0; j < (int)AdjList[u.first].size(); ++j) {
				// printf("Can move to room %d from %d\n", AdjList[u.first][j], u.first);
				if (!(u.second & (1 << AdjList[u.first][j])))
					continue; // light is off, can't go there
				ii v = {AdjList[u.first][j], u.second};
				if (dist.count(v) == 0) {
					dist[v] = dist[u] + 1;
					p[v] = u;
					q.push(v);
				}
			}
			// explore: flip switch
			for (int j = 0; j < (int)SwitchList[u.first].size(); ++j)
			{
				// printf("Can switch light in room %d from %d\n", AdjList[u.first][j], u.first);
				// printf("Lights before: %s\n", printBin(u.second).c_str());
				ii v = {u.first, u.second ^ (1 << SwitchList[u.first][j])};
				// printf("Lights after: %s\n\n", printBin(v.second).c_str());
				if (!(v.second & (1 << v.first)))
					continue;  // can't turn off the light in this room
				if (dist.count(v) == 0) {
					dist[v] = dist[u] + 1;
					p[v] = u;
					q.push(v);
				}
			}
		}
		printf("Villa #%d\n", ++caseno);
		if (dist.count(t) == 0)
			printf("The problem cannot be solved.\n");
		else
		{
			printf("The problem can be solved in %d steps:\n", dist[t]);
			printPath(t, t);
		}
		printf("\n");

		// next input
		cin >> R >> D >> S;
	}

	return 0;
}
