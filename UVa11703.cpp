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

#define N 1000000

ll dp[N+1];

ll x(int i) {
    if (dp[i] != -1) return dp[i];

    if (i == 0) return dp[i] = 1;
    else
        return dp[i] = (x((int)floorl(i - sqrtl(i))) % 1000000 +
                        x((int)floorl(logl(i))) % 1000000 +
                        x((int)floorl(i * powl(sinl(i),2))) % 1000000)
                       % 1000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    memset(dp, -1, sizeof(dp));
    int i; cin >> i;
    while (i != -1) {
        cout << x(i) << endl;
        cin >> i;
    }

    return 0;
}
