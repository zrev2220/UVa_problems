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
	// build Catalan numbers bottom-up
	vi cat(11); cat[0] = 1;
	for (int i = 1; i <= 10; ++i)
		cat[i] = (int) ((double) (2*i*((2*i)-1))/((i+1)*i) * cat[i - 1]);
	int n;
	bool first = true;
	while (scanf("%d", &n) != EOF)
	{
		if (first)
			first = false;
		else
			printf("\n");
		printf("%d\n", cat[n]);
	}
	return 0;
}
