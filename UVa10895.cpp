// Not tested yet - WIP
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

int main()
{
	int m, n;
	while (scanf("%d %d\n", &m, &n) != EOF)
	{
		vector<vi> elems(n, vi(m));
		for (int i = 0; i < m; i++)
		{
			int r; scanf("%d ", &r);
			vi cols(r);
			for (int j = 0; j < r; j++)
			{
				int c; scanf("%d", &c);
				cols.push_back(c);
			}
			for (int j = 0; j < r; j++)
			{
				int x; scanf("%d", &x);
				elems.at(cols.at(j)).at(r) = x;
			}
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d", (int) elems.at(i).size());
			for (int j = 0; j < m; j++)
			{
				if (elems.at(i).at(j) != 0)
					printf(" %d", j);
			}
			for (int j = 0; j < m; j++)
			{
				if (elems.at(i).at(j) != 0)
					printf("%s%d", j != 0 ? " " : "", elems.at(i).at(j));
			}
		}
	}
	return 0;
}
