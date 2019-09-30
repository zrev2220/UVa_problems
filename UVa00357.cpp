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

#define MAXN 30001
#define COINN 5
int coins[COINN] = {1, 5, 10, 25, 50};
ll dp[MAXN][COINN];

ll ways(int n, int i) {
    if (n < 0 || i >= COINN) return 0;
    else if (n == 0) return 1;
    else if (dp[n][i] != -1) return dp[n][i];
    else return dp[n][i] = ways(n - coins[i], i) + ways(n, i + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    while (cin) {
        ll ans = ways(n, 0);
        if (ans == 1L) cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;

        cin >> n;
    }

    return 0;
}
