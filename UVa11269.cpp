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

bool comp(ii a, ii b)
{
	int theMin = min({a.first, a.second, b.first, b.second});
	if (theMin == a.first || theMin == b.second)
		return true;
	return false;
}

int main()
{
	int p;
	while (scanf("%d\n", &p) != EOF)
	{
		vii probs;
		for (int i = 0; i < p; i++)
		{
			int a; scanf("%d", &a);
			probs.push_back(make_pair(a, -1));
		}
		for (int i = 0; i < p; i++)
		{
			int b; scanf("%d", &b);
			probs.at(i).second = b;
		}
		sort(probs.begin(), probs.end(), comp);
		int time = 0;
		int gwork = 0;
		for (ii pb : probs)
		{
			time += pb.first;
			gwork = max(0, gwork - pb.first);
			gwork += pb.second;
		}
		time += gwork;
		printf("%d\n", time);
	}
	return 0;
}
