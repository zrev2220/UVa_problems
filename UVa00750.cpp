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

vector<string> ans;
int requiredCol;
int requiredRow;
string curans;

void queens(int row, int colbm, int diag1, int diag2) {
    if (row > requiredRow && curans[requiredCol] != '0' + (char)requiredRow)
        return;
    if (row == 8) {
        ans.push_back(curans);
        return;
    } else {
        int taken = colbm | diag1 | diag2;
        FOR (i, 8) {
            if (~taken & (1 << (i))) {
                // try this column
                curans[i] = '0' + (char)row;
                // cout << (colbm | (1 << i)) << " " << ((diag1 << 1) | (1 << (i + 1))) << " " << ((diag2 >> 1) | (1 << (i - 1))) << endl;
                queens(row + 1, colbm | (1 << (i)), (diag1 << 1) | (1 << (i + 1)), (diag2 >> 1) | (1 << (i - 1)));
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
        ans.clear();
        curans = "........";

        int r, c; cin >> r >> c;
        --r, --c;
        requiredCol = c;
        requiredRow = r;

        // queens(0, 1 << (c), (1 << (c + r)), (1 << (c - r)));
        queens(0, 0, 0, 0);
        sort(ans.begin(), ans.end());

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        FOR (i, (int)ans.size()) {
            cout << setw(2) << (i + 1) << "     ";
            FOR (j, 8)
                cout << " " << (char)(ans[i][j] + 1);
            cout << endl;
        }

        if (t) cout << endl;
    }
    

    return 0;
}
