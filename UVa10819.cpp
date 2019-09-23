#include <bits/stdc++.h>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> T_AdjList;
typedef vector<vii> T_WAdjList;
#define INF 1000000000
#define FOR(i,a) for (int i = 0; i < a; ++i)
#define FORI(it,v) for (auto it = (v).begin(); it != (v).end(); ++it)
#define ROUND(d) (int)((double)(d) + 0.5)

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

#define MAXM 10201
#define MAXN 100
#define COST first
#define VALUE second
int m, n;
vii items;
vector<vi> dp;

int doit(int budget, int i) {
    // FOR(_, i) cout << " ";
    // cout << "doit(" << budget << ", " << i << ") → ";
    if (i > n) {
        // cout << "At end!" << endl;
        return 0;
    }
    if (dp[budget][i] != -1) {
        // cout << "In DP" << endl;
        return dp[budget][i];
    }

    if (items[i].COST > budget) {
        // cout << "Too much" << endl;
        return dp[budget][i] = doit(budget, i + 1);
    }
    else {
        // cout << endl;
        return dp[budget][i] = max(doit(budget - items[i].COST, i + 1) + items[i].VALUE,
                                   doit(budget,                 i + 1)
                               );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    cin >> m >> n;
    while (cin) {
        if (m > 2000 - 200) m += 200;
        dp.clear();
        dp.assign(m+1, vi(n, -1));
        items.assign(n, ii());
        FOR(i, n) cin >> items[i].COST >> items[i].VALUE;
        cout << doit(m, 0) << endl;
        // FOR(i, m) {
        //     cout << setw(5) << i << ": ";
        //     FOR(j, n) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cin >> m >> n;
    }

    return 0;
}
