#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main()
{
	int n;
	while (scanf("%d\n", &n) != EOF)
	{
		vector<vi> field(n, vi(n));
		vii ones, threes;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x; scanf("%1d", &x);
				field.at(i).at(j) = x;
				if (x == 1)
					ones.push_back(make_pair(i, j));
				else if (x == 3)
					threes.push_back(make_pair(i, j));
			}
		}
		int maxSteps = 0;
		for (ii one : ones)
		{
			int minSteps = -1;
			for (ii three : threes)
			{
				int dist = abs(one.first - three.first) + abs(one.second - three.second);
				if (minSteps == -1) minSteps = dist;
				else
					minSteps = min(minSteps, dist);
			}
			maxSteps = max(maxSteps, minSteps);
		}
		printf("%d\n", maxSteps);
	}
	return 0;
}
