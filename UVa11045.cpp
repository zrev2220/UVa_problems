#include <cmath>
#include <cstring>
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
#define MAX_V 38

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
                         res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main()
{
	int T; scanf("%d\n", &T);
	while (T--)
	{
		int n, m; scanf("%d %d\n", &n, &m);
		memset(res, 0, sizeof res);
		// use 0 for source, 1 for sink
		s = 0; t = 1;
		// 2-7 for sizes XS-XXL
		// 8+ for each person
		for (int i = 0; i < m; ++i)
		{
			int u = i + 8;
			res[s][u] = 1;
			for (int j = 0; j < 2; ++j)
			{
				int v = -1;
				char size[3]; scanf(" %s", size);
				if (strcmp(size, "XS") == 0)
					v = 2;
				else if (strcmp(size, "S") == 0)
					v = 3;
				else if (strcmp(size, "M") == 0)
					v = 4;
				else if (strcmp(size, "L") == 0)
					v = 5;
				else if (strcmp(size, "XL") == 0)
					v = 6;
				else if (strcmp(size, "XXL") == 0)
					v = 7;
				res[u][v] = 1;
			}
            scanf("\n");
		}
		// set size quantities
		for (int i = 2; i <= 7; ++i)
		{
			res[i][t] = n / 6;
		}
		
		mf = 0;                                              // mf stands for max_flow
		  while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
			f = 0;
			// run BFS, compare with the original BFS shown in Section 4.2.2
			vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
			p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
			while (!q.empty()) {
			  int u = q.front(); q.pop();
			  if (u == t) break;      // immediately stop BFS if we already reach sink t
			  for (int v = 0; v < MAX_V; v++)                 // note: this part is slow
				if (res[u][v] > 0 && dist[v] == INF)
				  dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}
			augment(t, INF);     // find the min edge weight `f' along this path, if any
			if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
			mf += f;                 // we can still send a flow, increase the max flow!
		  }
		
		printf("%s\n", mf < m ? "NO" : "YES");
	}
	return 0;
}
