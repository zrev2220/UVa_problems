#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

template <typename T>
class GenericUnionFind
{
	vi p;
	int nSets;
	int idx;
	map<T, int> keymap;
	int findSetIdx(int u) { if (p[u] < 0) return u; else return p[u] = findSetIdx(p[u]); }
public:
	GenericUnionFind(int N) { p.assign(N, -1); nSets = N; idx = 0; }
	int findSet(T key) {
		if (keymap.count(key) == 0)
		{
			keymap[key] = idx;
			if (idx == (int) p.size())
				p.push_back(-1);
			++idx;
		}
		return findSetIdx(keymap[key]);
	}
	int unionSet(T u, T v) {
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
	int T; cin >> T;
	while (T--)
	{
		int m; cin >> m;
		GenericUnionFind<string> uf(1);
		while (m--)
		{
			string u, v; cin >> u >> v;
			printf("%d\n", uf.unionSet(u, v));
		}
	}
	
	return 0;
}
