// Not AC yet, RTE
// Passes sample test case, uDebug test cases, and almost all discussion test cases
// But crashes on one discussion test case, but it doesn't look like a valid test (# of letters > n)
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

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
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
	int n, m;
	while (scanf("%d\n%d\n", &n, &m) != EOF) {
		UnionFind brain(n);
		char wake[3]; scanf("%s\n", wake);
		vector<vi> AdjList(n);
		vi bfs_num(n, 0);
		map<char, int> sectorNums;
		int nextnum = 0;
		sectorNums[wake[0]] = nextnum++;
		sectorNums[wake[1]] = nextnum++;
		sectorNums[wake[2]] = nextnum++;
		bfs_num.at(sectorNums[wake[0]]) = 1;
		bfs_num.at(sectorNums[wake[1]]) = 1;
		bfs_num.at(sectorNums[wake[2]]) = 1;
		brain.unionSet(sectorNums[wake[0]], sectorNums[wake[1]]);
		brain.unionSet(sectorNums[wake[0]], sectorNums[wake[2]]);
		printf("We've got %d awake.\n", brain.sizeOfSet(sectorNums[wake[0]]));
		for (int i = 0; i < m; i++)
		{
			int u, v; char uc, vc; scanf("%c%c\n", &uc, &vc);
			if (sectorNums.find(uc) == sectorNums.end())
				sectorNums[uc] = nextnum++;
			if (sectorNums.find(vc) == sectorNums.end())
				sectorNums[vc] = nextnum++;
			u = sectorNums[uc]; v = sectorNums[vc];
			printf("%d-%d\n", u, v);
			if (bfs_num.at(u) == 1 && bfs_num.at(v) == 1)
				brain.unionSet(u, v);
			AdjList.at(u).push_back(v);
			AdjList.at(v).push_back(u);
		}
		scanf("\n\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d:", i);
			for (int j = 0; j < (int) AdjList.at(i).size(); j++)
			{
				int v = AdjList.at(i).at(j);
				printf(" %d", v);
			}
			printf("\n");
		}
		int years = 0;
		while (true)
		{
			vi wakeUp;
			for (int i = 0; i < n; i++)
			{
				if (bfs_num.at(i) == 0)
				{
					int awake = 0;
					for (int j = 0; j < (int) AdjList.at(i).size(); j++)
					{
						if (bfs_num.at(AdjList.at(i).at(j)) == 1)
							awake++;
					}
					printf("%d is next to %d awake\n", i, awake);
					if (awake >= 3)
					{
						wakeUp.push_back(i);
					}
				}
			}
			if (!wakeUp.empty())
			{
				for (int i = 0; i < (int) wakeUp.size(); i++)
				{
					bfs_num.at(wakeUp.at(i)) = 1;
					printf("Year %d, Woke up %d\n", years, wakeUp.at(i));
					brain.unionSet(wakeUp.at(i), sectorNums[wake[0]]);
					printf("We've got %d awake.\n", brain.sizeOfSet(sectorNums[wake[0]]));
				}
				years++;
			}
			else
				break;
		}
		printf("We've got %d awake.\n", brain.sizeOfSet(sectorNums[wake[0]]));
		if (brain.sizeOfSet(sectorNums[wake[0]]) == n)
			printf("WAKE UP IN, %d, YEARS\n", years);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}
