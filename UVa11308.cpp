#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main()
{
	int T; cin >> T;
	while (T--)
	{
		string binderName; getline(cin, binderName); getline(cin, binderName); // getline twice to strip old newline char
		int ingedients, recipes, budget; cin >> ingedients >> recipes >> budget;
		unordered_map<string, int> ingredMap;
		for (int i = 0; i < ingedients; ++i)
		{
			string ingredStr;
			int cost;
			cin >> ingredStr >> cost;
			ingredMap[ingredStr] = cost;
		}
		priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> affordable;
		for (int i = 0; i < recipes; ++i)
		{
			string recipeName; getline(cin, recipeName); getline(cin, recipeName);
			int reqIngreds; cin >> reqIngreds;
			int curCost = 0;
			while (reqIngreds--)
			{
				string ingred; int quant; cin >> ingred >> quant;
				curCost += ingredMap[ingred] * quant;
			}
			if (curCost <= budget)
				affordable.push(make_pair(curCost, recipeName));
		}
		transform(binderName.begin(), binderName.end(), binderName.begin(), ::toupper);
		cout << binderName << endl;
		if (affordable.empty())
			cout << "Too expensive!" << endl;
		else
		{
			while (!affordable.empty())
			{
				cout << affordable.top().second << endl;
				affordable.pop();
			}
		}
		cout << endl;
	}
	return 0;
}
