// faster than UVa11597.py approach
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
	int caseno = 0, n; scanf("%d", &n);
	while (n != 0)
	{
		printf("Case %d: %d\n", ++caseno, n / 2);
		scanf("%d", &n);
	}
	return 0;
}
