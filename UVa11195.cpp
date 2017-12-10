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
#define MAX_N 15

vi grid;
int ans = 0, OK;
int col = -1;
int prevRow = 0;

string printBin(int x)
{
	string result = "";
	for (int j = 0; j < (int)grid.size(); ++j)
		result += ((x & (1 << j)) ? "1" : "0");
	return result;
}

int LSOneIdx(int x)
{
	for (int i = 0; i < 32; ++i)
	{
		if (x & (1 << i))
			return i;
	}
	return -1;
}

void backtrack(int row, int ldiag, int rdiag, bool bad)
{
	++col;
	if (bad) return;
	if (row == OK) {ans++; return;}
	int pos = OK & (~(row | ldiag | rdiag));
	for (int i = 0; i < col; ++i)
		cout << " ";
	cout << printBin(pos) << endl;
	while (pos)
	{
		int p = pos & -pos;
		pos -= p;
		backtrack(row | p, (ldiag | p) << 1, (rdiag | p) >> 1, col < (int)grid.size() && (grid.at(col) & p));
		--col;
	}
}

int main()
{
	int n; cin >> n;
	int caseno = 0;
	while (n != 0)
	{
		ans = 0;
		OK = (1 << n) - 1;
		grid.assign(n, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				char c; cin >> c;
				if (c == '*')
				{
					grid.at(j) |= 1 << i;
				}
			}
		}
		backtrack(0, 0, 0, 0);
		printf("Case %d: %d\n", ++caseno, ans);

		cin >> n;
	}
	return 0;
}
