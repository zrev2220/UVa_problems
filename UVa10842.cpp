#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
	int T; scanf("%d\n", &T);
	int caseno = 0;
	while (T--)
	{
		++caseno;
		int V, E, u, v, w;
		scanf("%d %d\n", &V, &E);
		vector< pair<int, ii> > EdgeList;
		for (int i = 0; i < E; ++i)
		{
			scanf("%d %d %d\n", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end(), greater<pair<int, ii>>());
		
		int mst_cost = 0;
		UnionFind UF(V);                     // all V are disjoint sets initially
		int lastRoad = ~(1 << 31);
		for (int i = 0; i < E; i++) {                      // for each edge, O(E)
			pair<int, ii> front = EdgeList.at(i);
			if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
				mst_cost += front.first;                // add the weight of e to MST
				lastRoad = min(lastRoad, front.first);
				UF.unionSet(front.second.first, front.second.second);    // link them
			}
		}
		printf("Case #%d: %d\n", caseno, lastRoad);
	}
	return 0;
}
