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

#define MAXM 20201
#define MAXN 100
#define COST first
#define VALUE second
int m, n;
vii items;
int dp[MAXM][MAXN];

int doit(int spent, int i) {
    if (i >= n)             return ((spent > 2000 && spent <= m + 200) || spent <= m) ? 0 : -INF;
    if (dp[spent][i] != -1) return dp[spent][i];

    if (spent > m + 200)    return -INF;
    else
        return dp[spent][i] = max(doit(spent + items[i].COST, i + 1) + items[i].VALUE,
                                  doit(spent,                 i + 1)
                              );
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    cin >> m >> n;
    while (cin) {
        memset(dp, -1, sizeof(dp[0][0]) * MAXM * MAXN);
        items.assign(n, ii());
        FOR(i, n) cin >> items[i].COST >> items[i].VALUE;
        cout << doit(0, 0) << endl;

        cin >> m >> n;
    }

    return 0;
}
