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

int m, c;
vector<vi> garments;
vector<vi> dp;

int buy(int g, int money) {
    // printf("%d, %d\n", g, money);
    if (dp[g][money] != -1) return dp[g][money];
    if (g == c) return dp[g][money] = 0;
    if (money <= 0) return dp[g][money] = INF;
    int ans = -1;
    FOR(i, (int)garments[g].size()) {
        if (money >= garments[g][i]) {
            int b = buy(g + 1, money - garments[g][i]);
            // printf("buy returned %d\n", b);
            if (b < INF)
                ans = max(ans, b + garments[g][i]);
        }
    }
    return dp[g][money] = ans == -1 ? INF : ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // code goes here
    int n; cin >> n;
    while (n--) {
        cin >> m >> c;
        garments.assign(c+1, vi());
        dp.assign(c+1, vi(m+1, -1));
        FOR(i, c) {
            int k; cin >> k;
            FOR(j, k) {
                int x; cin >> x;
                garments[i].push_back(x);
            }
        }
        int ans = buy(0, m);
        if (ans >= INF) cout << "no solution";
        else cout << ans;
        cout << endl;
        // FOR(i, dp.size()) {
        //     FOR(j, dp[i].size()) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
