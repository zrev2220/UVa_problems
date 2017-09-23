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
	int t; scanf("%d\n\n", &t);
	while (t--)
	{
		int w; scanf("%d\n", &w);
		int diff = -1;
		bool can = true;
		for (int i = 0; i < w; i++)
		{
			int y1, y2; scanf("%d %d\n", &y1, &y2);
			if (diff == -1) diff = y1 - y2;
			else if (y1 - y2 != diff) can = false;
		}
		printf("%s\n", can ? "yes" : "no");
		if (t != 0)
			printf("\n");
	}
	return 0;
}
