#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<char>> grid;
int R, C;

int floodfill(int r, int c, char c1, char c2)
{
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (grid.at(r).at(c) != c1) return 0;
	int ans = 1;
	grid.at(r).at(c) = c2;
	for (int i = 0; i < 8; i++)
		ans += floodfill(r + dr[i], c + dc[i], c1, c2);
	return ans;
}

int main()
{
	int t; scanf("%d\n", &t);
	while (t--)
	{
		grid.clear();
		R = C = 0;
		scanf("\n");
		string line = "foo";
		vector<string> lines;
		vii queries;
		while (line != "" && getline(cin, line))
		{
			lines.push_back(line);
			if (regex_match(line, basic_regex<char>("[LW]+")))
			{
				vector<char> row;
				for (int i = 0; i < (int) line.length(); i++)
					row.push_back(line.at(i));
				grid.push_back(row);
			}
			else if (regex_match(line, basic_regex<char>("[0-9 ]+")))
			{
				int a, b;
				int space = line.find(" ");
				a = stoi(line.substr(0, line.length() - space));
				b = stoi(line.substr(space));
				queries.push_back(make_pair(a, b));
			}
		}
		R = grid.size();
		C = grid.at(0).size();
		for (ii q : queries)
		{
			printf("%d\n", floodfill(q.first - 1, q.second - 1, 'W', '*'));
			floodfill(q.first - 1, q.second - 1, '*', 'W');
		}
		if (t != 0)
			printf("\n");
	}
	return 0;
}
