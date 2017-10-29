#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class UnionFindK
{
	vi p;
	int nSets;
public:
	UnionFindK(int N) { p.assign(N, -1); nSets = N; }
	int findSet(int u) { if (p[u] < 0) return u; else return p[u] = findSet(p[u]); }
	int unionSet(int u, int v) {
		int uSet = findSet(u);
		int vSet = findSet(v);
		if (uSet != vSet) {
			if (-p[vSet] > -p[uSet]) swap(uSet, vSet);
			p[uSet] += p[vSet];
			p[vSet] = uSet;
			--nSets;
		}
		return -p[uSet]; // return size
	}
	int sizeOfSet(int u) { return -p[findSet(u)]; }
	int numberOfSets() { return nSets; }
};

int main()
{
	int T; scanf("%d\n", &T);
	while (T--)
	{
		int n, m; scanf("%d %d\n", &n, &m);
		UnionFindK uf(n);
		int maxSize = 1;
		while (m--)
		{
			int u, v; scanf("%d %d\n", &u, &v);
			maxSize = max(maxSize, uf.unionSet(--u, --v));
		}
		printf("%d\n", maxSize);
	}
	
	return 0;
}
