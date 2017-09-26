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
	int t; scanf("%d\n\n", &t);
	while (t--)
	{
		ii don, lep;
		int x, y; scanf("%d %d\n", &x, &y);
		don = make_pair(x, y);
		scanf("%d %d\n", &x, &y);
		lep = make_pair(x, y);
		int l; scanf("%d\n", &l);
		queue<ii> lepPath;
		for (int i = 0; i < l; i++)
		{
			scanf("%d %d\n", &x, &y);
			lepPath.push(make_pair(x, y));
		}
		int d; scanf("%d\n", &d);
		queue<ii> donPath;
		for (int i = 0; i < d; i++)
		{
			scanf("%d %d\n", &x, &y);
			donPath.push(make_pair(x, y));
		}
		scanf("\n");
		// printf("don: %d,%d	lep: %d,%d\n", don.first, don.second, lep.first, lep.second);
		while (!lepPath.empty())
		{
			// move lep and don
			// if their location is ==, "no"
			// if lep finishes, "yes"
			ii nextLep = lepPath.front();
			if (lep.first == nextLep.first)
			{
				// move y
				if (lep.second < nextLep.second)
					lep.second++;
				else
					lep.second--;
			}
			else
			{
				// move x
				if (lep.first < nextLep.first)
					lep.first++;
				else
					lep.first--;
			}
			// pop stop if reached
			if (lep == nextLep)
				lepPath.pop();
			ii nextDon = donPath.front();
			if (don.first == nextDon.first)
			{
				// move y
				if (don.second < nextDon.second)
					don.second++;
				else
					don.second--;
			}
			else
			{
				// move x
				if (don.first < nextDon.first)
					don.first++;
				else
					don.first--;
			}
			// pop stop if reached
			if (don == nextDon)
				donPath.pop();
			// printf("don: %d,%d	lep: %d,%d\n", don.first, don.second, lep.first, lep.second);
			if (don == lep && !lepPath.empty())
			{
				printf("No\n");
				break;
			}
		}
		if (lepPath.empty())
			printf("Yes\n");
		if (t != 0)
			printf("\n");
	}
	return 0;
}
