#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main()
{
	int t; scanf("%d\n", &t);
	while (t--)
	{
		int n, m; scanf("%d %d\n", &n, &m);
		vector<bitset<32>> prefers(m);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int p; scanf("%d", &p);
				if (p == 1)
					prefers.at(i).set(j);
			}
			scanf("\n");
		}
		ll ans = 1ll;
		for (int i = 0; i < n; ++i)
		{
			int prefs = 0;
			for (int j = 0; j < m; ++j)
			{
				if (prefers.at(j).test(i))
					++prefs;
			}
			ans *= (ll) (prefs == 0) ? 1 : prefs;
		}
		printf("%d\n", ans);
	}
	return 0;
}
