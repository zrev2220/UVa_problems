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

int m;
vi vessels;

bool can(int max)
{
	int tanks = 0;
	int sum = 0;
	for (int v : vessels)
	{
		sum += v;
		if (sum > max)
		{
			tanks++;
			sum = v;
			if (tanks == m)
				return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (scanf("%d %d\n", &n, &m) != EOF)
	{
		vessels.clear();
		int lo = 0;
		int hi = 0;
		for (int i = 0; i < n; i++)
		{
			int v; scanf("%d", &v);
			lo = max(lo, v);
			hi += v;
			vessels.push_back(v);
		}
		if (m == 1)
			printf("%d\n", hi);
		else
		{
			int ans = 0;
			while (lo != hi)
			{
				int mid = (lo + hi) / 2;
				if (can(mid)) {ans = mid; hi = mid;}
				else lo = mid + 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
