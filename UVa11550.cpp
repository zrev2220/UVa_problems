#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <unordered_set>
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
		vector<bitset<8>> columns(m, 0);
		bool valid = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int e; scanf("%d", &e);
				if (e)
					columns[j].set(i);
			}
			scanf("\n");
		}
		unordered_set<bitset<8>> incidence;
		for (bitset<8> col : columns)
		{
			if (col.count() != 2 || incidence.find(col) != incidence.end())
			{
				valid = false;
				break;
			}
			else
				incidence.insert(col);
		}
		printf("%s\n", valid ? "Yes" : "No");
	}
	return 0;
}
