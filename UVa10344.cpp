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

ll nums[5] = {-1, -1, -1, -1, -1};
#define ANS 23

bool rec(int i, ll val) {
    if (i == 5) {
        return val == ANS;
    } else if (i == 0) {
        return rec(i + 1, nums[i]);
    } else {
        return rec(i + 1, val + nums[i]) ||
               rec(i + 1, val + -nums[i]) ||
               rec(i + 1, (i == 0 ? 1 : val) * nums[i]);
    }
}

bool done() {
    bool ans = true;
    FOR(i, 5) {
        ans = ans && nums[i] == 0;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    while (1) {
        FOR(i,5) cin >> nums[i];
        if (done()) break;

        sort(nums, nums + 5);
        bool ans = false;
        while (next_permutation(nums, nums + 5) && !(ans = rec(0, 0))) ;
        cout << (ans ? "Possible" : "Impossible") << endl;
    }

    return 0;
}
