// WIP, doesn't pass sample yet
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

vector<vi> memo;

int main()
{
	int p; scanf("%d\n", &p);
	while (p--)
	{
		int s; scanf("%d\n", &s);
		int n; scanf("%d\n", &n);
		vector<vector<bool>> grid(s, vector<bool>(s, false));
		memo.assign(s, vi(s, -1));
		for (int i = 0; i < n; i++)
		{
			int r1, c1, r2, c2; scanf("%d %d %d %d\n", &r1, &c1, &r2, &c2);
			r1--; c1--; r2--; c2--;
			for (int j = r1; j <= r2; j++)
			{
				for (int k = c1; k <= c2; k++)
				{
					grid.at(j).at(k) = true;
				}
			}
		}
		int maxSize = 0;
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s; j++)
			{
				if ((i == 0 && j == 0) || grid.at(i).at(j))
					memo.at(i).at(j) = 0;
				else if (i == 0)
				{
					memo.at(i).at(j) = memo.at(i).at(j - 1) + 1;
				}
				else if (j == 0)
				{
					memo.at(i).at(j) = memo.at(i - 1).at(j) + 1;
				}
				else
				{
					memo.at(i).at(j) = memo.at(i - 1).at(j) + memo.at(i).at(j - 1) - memo.at(i - 1).at(j - 1) + 1;
				}
				maxSize = max(maxSize, memo.at(i).at(j));
				printf("%4d ", memo.at(i).at(j));
			}
			printf("\n");
		}
		printf("%d\n", maxSize);
	}
	return 0;
}
