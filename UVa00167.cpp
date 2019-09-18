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

ll best;
ll board[8][8];

void queens(int row, int colbm, int diag1, int diag2, ll score) {
    if (row == 8) {
        best = max(best, score);
        return;
    } else {
        int taken = colbm | diag1 | diag2;
        FOR (i, 8) {
            if (~taken & (1 << (i))) {
                // try this column
                queens(row + 1, colbm | (1 << (i)), (diag1 << 1) | (1 << (i + 1)), (diag2 >> 1) | (1 << (i - 1)), score + board[row][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // code goes here
    int t; cin >> t;
    while (t--) {
        FOR(i, 64) {
            cin >> board[i / 8][i % 8];
        }
        best = 0;
        queens(0, 0, 0, 0, 0L);
        cout << setw(5) << best << endl;
    }

    return 0;
}
