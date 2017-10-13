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
	vi nums;
	int x;
	while (scanf("%d\n", &x) != EOF)
	{
		if (nums.empty())
		{
			nums.push_back(x);
			printf("%d\n", x);
			continue;
		}
		// use insertion sort; faster than mergesort when inserting items one at a time
		for (int i = 0; i <= (int) nums.size(); ++i)
		{
			if (i == (int) nums.size())
			{
				nums.push_back(x);
				break;
			}
			if (x < nums[i])
			{
				nums.insert(nums.begin() + i, x);
				break;
			}
		}
		if ((int) nums.size() % 2 == 0)
			printf("%d\n", (nums.at(nums.size() / 2) + nums.at(nums.size() / 2 - 1)) / 2);
		else
			printf("%d\n", nums.at(nums.size() / 2));
	}
	return 0;
}
