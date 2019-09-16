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

typedef pair<int, pair<ii, ii>> patch;

int n, m;

string printBin(int x)
{
	string result = "";
	for (int j = 0; j < n; ++j)
		result += ((x & (1 << j)) ? "1" : "0");
	return result;
}

bool patchWorks(patch p, int state)
{
	ii src = p.second.first;
	return ((state & src.first) == src.first) && ((~(state) & src.second) == src.second);
}

int applyPatch(patch p, int state)
{
	ii dest = p.second.second;
	state |= dest.first;
	state &= ~dest.second;
	return state;
}

int main()
{
	int s;
	cin >> n >> m; s = 0;
	int caseno = 0;
	while (cin && (n != 0 || m != 0))
	{
		vector<patch> patches;
		for (int i = 0; i < m; ++i)
		{
			int time; string src, dest; cin >> time >> src >> dest;
			if (src != dest)
			{
				int minus1 = 0, minus2 = 0, plus1 = 0, plus2 = 0;
				for (int j = 0; j < n; ++j)
				{
					if (src[j] == '-')
						minus1 |= 1 << j;
					else if (src[j] == '+')
						plus1 |= 1 << j;
					if (dest[j] == '-')
						minus2 |= 1 << j;
					else if (dest[j] == '+')
						plus2 |= 1 << j;
				}
				patches.push_back({time, {{minus1, plus1}, {minus2, plus2}}});
			}
		}
		m = (int)patches.size();
		int bugfree = (1 << n) - 1;

		map<int, int> dist; dist[s] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
		while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (dist.count(u) == 1 && d > dist[u]) continue;
			for (int j = 0; j < m; ++j) {
				patch p = patches[j];
				if (!patchWorks(p, u)) continue;
				ii v = {applyPatch(p, u), p.first};
				if (dist.count(v.first) == 0 || dist[u] + v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
		} } }
		printf("Product %d\n", ++caseno);
		if (dist.count(bugfree) == 0)
			printf("Bugs cannot be fixed.\n\n");
		else
			printf("Fastest sequence takes %d seconds.\n\n", dist[bugfree]);

		// next input
		cin >> n >> m; s = 0;
	}

	return 0;
}
