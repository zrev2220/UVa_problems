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

vi tracks;
ii best;
int cap;

void fun(int idx, int space, int used) {
    if (space < 0) return;
    if (space == 0) {
        best = ii(cap - space, used);
        return;
    }
    if (idx >= (int)tracks.size()) {
        if ((cap - space) > best.first)
            best = ii(cap - space, used);
        return;
    }

    fun(idx + 1, space - tracks[idx], used | (1 << idx));
    fun(idx + 1, space, used);
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    
    while (true) {
        int n;
        cin >> cap >> n;
        if (!cin) break;
        tracks.assign(n, 0);
        FOR(i, n)
            cin >> tracks[i];
        best = ii(0, 0);
        fun(0, cap, 0);

        FOR(i, n) {
            if (best.second & (1 << i))
                cout << tracks[i] << " ";
        }
        cout << "sum:" << best.first << endl;
    }

    return 0;
}
