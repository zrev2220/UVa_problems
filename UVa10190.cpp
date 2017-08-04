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
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int ans = n;
		bool boring = m < 2 || ans % m != 0 || m > n;
		vi seq;
		seq.push_back(n);
		while (ans != 1)
		{
			if (m < 2 || ans % m != 0 || m > n)
			{
				boring = true;
				break;
			}
			ans /= m;
			seq.push_back(ans);
		}
		if (boring)
			printf("Boring!\n");
		else
		{
			for (int i = 0; i < (int) seq.size(); i++)
			{
				if (i > 0)
					printf(" ");
				printf("%d", seq.at(i));
			}
			printf("\n");
		}
	}
	return 0;
}
