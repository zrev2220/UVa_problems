#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

#define MAX_V 100

bool DEBUG;
int res[MAX_V][MAX_V], mf, f, s, t; // global variables
vi p;

void augment(int v, int minEdge) { // traverse BFS spanning tree from s to t
	if (v == s) { f = minEdge; return; } // record minEdge in a global variable f
	else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
							res[p[v]][v] -= f; res[v][p[v]] += f;
							if(DEBUG){
							if (v != t) printf("%d > ", v + 1);
							else printf("%d\n", t + 1);}
							} // update
}

int main(int argc, char** argv) {
	DEBUG = argc > 1;
	int V; scanf("%d\n", &V);
	int caseno = 0;
	while (V != 0)
	{
		int c; scanf("%d %d %d\n", &s, &t, &c);
		--s; --t;
		memset(res, 0, sizeof res);
		for (int i = 0; i < c; ++i) {
			int u, v, w; scanf("%d %d %d\n", &u, &v, &w);
			res[--u][--v] += w;
			res[v][u] += w;
		}
		// printf("    ");
		// for (int i = 0; i < V; ++i)
			// printf(" %3d", i + 1);
		// printf("\n");
		// for (int i = 0; i < V; ++i)
		// {
			// printf("%3d:", i + 1);
			// for (int j = 0; j < V; ++j)
				// printf(" %3d", res[i][j]);
			// printf("\n");
		// }
		// printf("\n");

		mf = 0; // mf stands for max_flow
		while (1) { // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
			f = 0;
			// run BFS, compare with the original BFS shown in Section 4.2.2
			vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
			p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break; // immediately stop BFS if we already reach sink t
				for (int v = 0; v < MAX_V; v++) // note: this part is slow
					if (res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}
			if(DEBUG) {
			printf("-----------------\ni");
			for (int i = 0; i < V; ++i)
				printf(" %3d", i + 1);
			printf("\np");
			for (int i = 0; i < V; ++i)
				printf(" %3d", p[i] + 1);
			printf("\n . . . . . . . . .\nTook path %d > ", s + 1);}
			augment(t, INF); // find the min edge weight `f' along this path, if any
			if (f == 0) break; // we cannot send any more flow (`f' = 0), terminate
			mf += f; // we can still send a flow, increase the max flow!
			if(DEBUG)
			printf("Add flow %d\n", f);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", ++caseno, mf); // this is the max flow value
		scanf("%d\n", &V);
	}

	return 0;
}
