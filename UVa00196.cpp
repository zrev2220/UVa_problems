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

int r, c;
vector<string> sheet;

int getcol(string s) {
    // find end
    int pow[] = {1, 26, 26*26};
    int j = 0;
    while (s[j] >= 'A')
        ++j;

    int i = 0;
    int ans = 0;
    while (i != j) {
        ans += (int)(s[i] - 'A' + 1) * pow[(j - i - 1)];
        ++i;
    }
    return ans;
}

int eval(int idx) {
    // cout << "eval(" << idx << "); " << sheet[idx] << endl;
    if (sheet[idx][0] != '=') return stoi(sheet[idx]);
    // parse formula
    int result = 0;
    int i = 1;
    int col = -1;
    int row = -1;
    int level = 0;
    while (i < sheet[idx].length()) {
        if (col == -1 && sheet[idx][i] >= 'A' && sheet[idx][i] <= 'Z') {
            col = getcol(sheet[idx].substr(i));
        }
        else if (row == -1 && sheet[idx][i] >= '0' && sheet[idx][i] <= '9') {
            row = stoi(sheet[idx].substr(i));
        }
        else if (sheet[idx][i] == '+' || sheet[idx][i] == '$') {
            // cout << "going to eval(" << row << " * " << c << " + " << col << ") " << sheet[idx] << " " << i << " " << sheet[idx][i] << endl;
            result += eval((row - 1) * c + col - 1);
            // cout << "Evaluating " << sheet[idx] << " result = " << result << endl;
            col = -1;
            row = -1;
            level = 0;
        }
        ++i;
    }
    sheet[idx] = to_string(result);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // assert(getcol("A1$") == 1);
    // assert(getcol("A1+B2$") == 1);
    // assert(getcol("AA1$") == 27);
    // assert(getcol("BC6$") == 55);
    // assert(getcol("AAA3$") == 703);
    // assert(getcol("DGZ4$") == 2912);
    // code goes here
    int t; cin >> t;
    while (t--) {
        cin >> c >> r;
        sheet.assign(r * c, "");
        FOR(i, r) {
            FOR(j, c) {
                string cell; cin >> cell;
                if (cell[0] == '=')
                    cell += "$";
                sheet[i * c + j] = cell;
            }
        }
        // FOR(i, r) {
        //     FOR(j, c) {
        //         cout << sheet[i * c + j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "--------------\n";
        FOR(i, r) {
            FOR(j, c)
                cout << eval(i * c + j) << (j != c-1 ? " " : "");
            cout << endl;
        }
    }

    return 0;
}
