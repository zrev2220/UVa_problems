#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
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
		scanf("%d\n", &s); s--;
		scanf("%d\n", &t);
		scanf("%d\n", &E);
		vector<vii> AdjList(V, vii());
		for (int i = 0; i < E; ++i)
		{
			scanf("%d %d %d\n", &u, &v, &w);
			AdjList.at(--v).push_back(ii(--u, w));
		}
		scanf("\n");
		
		vi dist(V, INF); dist.at(s) = 0;                    // INF = 1B to avoid overflow
		  priority_queue<ii, vector<ii>, std::greater<ii>> pq; pq.push(ii(0, s));
									 // ^to sort the pairs by increasing distance from s
		  while (!pq.empty()) {                                             // main loop
			ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
			int d = front.first, u = front.second;
			if (d > dist.at(u)) continue;   // this check is important, see the explanation
			for (int j = 0; j < (int)AdjList.at(u).size(); j++) {
			  ii v = AdjList.at(u).at(j);                       // all outgoing edges from u
			  if (dist.at(u) + v.second < dist.at(v.first)) {
				dist.at(v.first) = dist.at(u) + v.second;                 // relax operation
				pq.push(ii(dist.at(v.first), v.first));
		  } } }  // note: this variant can cause duplicate items in the priority queue
		
		printf("%d\n", (int) count_if(dist.begin(), dist.end(), [t](const int d) -> bool{
			return d <= t;
		}));
		if (T != 0)
			printf("\n");
	}
	
	return 0;
}
