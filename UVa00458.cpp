#include <bits/stdc++.h>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define FOR(i,a) for (int i = 0; i < a; ++i)
#define FORI(it,v) for (auto it = (v).begin(); it != (v).end(); ++it)

template<typename T>
void printvi(vector<T> v, string sep=" ", string bookend="") {
	cout << bookend << ((bookend == "") ? "" : " ");
	for (T n : v)
		cout << n << sep;
	cout << bookend << endl;
}

void printvii(vector<ii> v, string sep=" ", string bookend="") {
	cout << bookend << ((bookend == "") ? "" : " ");
	for (ii p : v)
		cout << "(" << p.first << "," << p.second << ")" << sep;
	cout << bookend << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	// code goes here
	string word;
	while (getline(cin, word)) {
		string decode = "";
		for (char c : word) {
			if (c == 13 || c == 10)
				break;
			decode += char(c - 7);
		}
		cout << decode << endl;
	}

	return 0;
}
