#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

struct soldier
{
	int num, prev, next;
};

void printArmy(vector<soldier>& army)
{
	for (soldier x : army)
		printf("  % 3d ", x.num);
	printf("\n");
	for (soldier x : army)
		printf(" <% 3d ", x.prev);
	printf("\n");
	for (soldier x : army)
		printf("  % 3d>", x.next);
	printf("\n");
}

int main()
{
	int s, b; scanf("%d %d\n", &s, &b);
	while (s != 0 || b != 0)
	{
		vector<soldier> army;
		for (int i = 0; i < s; ++i)
			army.push_back({i + 1, i - 1, (i + 1 == s) ? -1 : i + 1});
		// printArmy(army);
		for (int i = 0; i < b; ++i)
		{
			int l, r; scanf("%d %d\n", &l, &r);
			int li = l - 1, ri = r - 1;
			int end = (army[li].prev == -1) ? ((army[ri].next == -1) ? -1 : army[ri].next) : (army[army[li].prev].next = army[ri].next);
			int start = (army[ri].next == -1) ? ((army[li].prev == -1) ? -1 : army[li].prev) : (army[army[ri].next].prev = army[li].prev);
			// printArmy(army);
			// printf("start = %d, end = %d\n", start + 1, end + 1);
			printf("%s %s\n", (start == -1) ? "*" : to_string(start + 1).c_str(), (end == -1) ? "*" : to_string(end + 1).c_str());
		}
		printf("-\n");

		scanf("%d %d\n", &s, &b);
	}
	return 0;
}
