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
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vi arr;
		vector<bool> abss(n - 1, false);
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			arr.push_back(x);
		}
		if (n == 1)
		{
			printf("Jolly\n");
			continue;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int absolute = abs(arr[i] - arr[i + 1]);
			if (absolute <= 0 || absolute >= n)
				break;
			abss.at(absolute - 1) = true;
		}
		if (find(abss.begin(), abss.end(), false) == abss.end())
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
