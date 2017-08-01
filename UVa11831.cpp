#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main()
{
	map<int, ii> d {
		{0, make_pair(0, 1)},
		{1, make_pair(-1, 0)},
		{2, make_pair(0, -1)},
		{3, make_pair(1, 0)}
	};
	int n, m, s; scanf("%d %d %d\n", &n, &m, &s);
	while (n != 0)
	{
		vector<vector<char>> grid;
		ii bot = make_pair(-1, -1);
		for (int i = 0; i < n; i++)
		{
			char* row = new char[m]; scanf("%s", row);
			grid.push_back(vector<char>(row, row + m));
			if (bot.first == -1)
				for (int j = 0; j < m; j++)
				{
					if (row[j] == 'N' || row[j] == 'S' || row[j] == 'L' || row[j] == 'O')
						bot = make_pair(j, i);
				}
			delete[] row;
		}
		char* todo = new char[s]; scanf("%s", todo);
		vector<char> instructions(todo, todo + s);
		int stickers = 0;
		int dir = -1;
		switch (grid.at(bot.second).at(bot.first))
		{
			case 'S':
				dir = 0;
				break;
			case 'O':
				dir = 1;
				break;
			case 'N':
				dir = 2;
				break;
			case 'L':
				dir = 3;
				break;
		}
		for (char dothis : instructions)
		{
			if (dothis == 'D')
				dir = (dir + 1 > 3) ? 0 : dir + 1;
			else if (dothis == 'E')
				dir = (dir - 1 < 0) ? 3 : dir - 1;
			else
			{
				ii moveTo = make_pair(bot.first + d[dir].first, bot.second + d[dir].second);
				if (!(moveTo.first < m && moveTo.first >= 0 && moveTo.second < n && moveTo.second >= 0))
					continue;
				char* cell = &grid.at(moveTo.second).at(moveTo.first);
				if (*cell != '#')
				{
					bot = moveTo;
					if (*cell == '*')
					{
						*cell = '.';
						stickers++;
					}
				}
			}
		}
		printf("%d\n", stickers);
		
		delete[] todo;
		scanf("%d %d %d", &n, &m, &s);
	}
	return 0;
}
