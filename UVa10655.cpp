#include <bits/stdc++.h>

using namespace std;
#define MAX_N 2
typedef long long ll;
struct Matrix {ll mat[MAX_N][MAX_N];};

Matrix matMul(Matrix a, Matrix b)
{
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; ++i)
        for (j = 0; j < MAX_N; ++j)
            for (ans.mat[i][j] = k = 0; k < MAX_N; ++k)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return ans;
}

Matrix matPow(Matrix base, int p)
{
    Matrix ans; int i, j;
    for (i = 0; i < MAX_N; ++i) for (j = 0; j < MAX_N; ++j)
        ans.mat[i][j] = (i == j);
    while (p)
    {
        if (p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false);
    int p, q, n; cin >> p >> q;
    while (cin >> n)
    {
        Matrix strt;
        strt.mat[0][0] = p;
        strt.mat[0][1] = -q;
        strt.mat[1][0] = 1;
        strt.mat[1][1] = 0;
        Matrix other;
        other.mat[0][0] = p;
        other.mat[1][0] = 2;
        strt = matPow(strt, n);
        strt = matMul(strt, other);
        cout << strt.mat[1][0] << endl;
        cin >> p >> q;
    }
    
    return 0;
}
