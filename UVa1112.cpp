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

int main()
{
	int T; scanf("%d\n\n", &T);
	while (T--)
	{
		int V, E, s, u, v, w, t;
		scanf("%d\n", &V);
		scanf("%d\n", &s);
		scanf("%d\n", &t);
		scanf("%d\n", &E);
		vector<vii> AdjList(V, vii());
		for (int i = 0; i < E; ++i)
		{
			scanf("%d %d %d\n", &u, &v, &w);
			AdjList.at(--u).push_back(ii(--v, w));
		}
		scanf("\n");
		
		vi dist(V, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
		  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
									 // ^to sort the pairs by increasing distance from s
		  while (!pq.empty()) {                                             // main loop
			ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;   // this check is important, see the explanation
			for (int j = 0; j < (int)AdjList[u].size(); j++) {
			  ii v = AdjList[u][j];                       // all outgoing edges from u
			  if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;                 // relax operation
				pq.push(ii(dist[v.first], v.first));
		  } } }  // note: this variant can cause duplicate items in the priority queue
		
		printf("%d\n", (int) count_if(dist.begin(), dist.end(), [t](const int d) -> bool{
			return d <= t;
		}));
		if (T != 0)
			printf("\n");
	}
	
	return 0;
}
