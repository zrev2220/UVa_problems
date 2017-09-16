#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = L;                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
  } }

  int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] >= A[p2]) ? p1 : p2; }          // as as in build routine
	
public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading
};

int main()
{
	int n, q;
	while (scanf("%d %d\n", &n, &q) == 2)
	{
		vi arr;
		vi freq;
        map<int, int> ends;
		int last = INF, occ = 1;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if (last != x)
			{
                ends[last] = i - 1;
				last = x;
				occ = 1;
			}
			else
				occ++;
			arr.push_back(x);
			freq.push_back(occ);
		}
		ends[last] = n - 1;
		#ifdef DEBUG
		for (int x : freq)
			printf("%d ", x);
		printf("\n");
		for (auto it = ends.begin(); it != ends.end(); it++)
			printf("%d: %d\n", it->first, it->second);
		#endif
		SegmentTree freqTree(freq);
		for (int i = 0; i < q; i++)
		{
			int l, r; scanf("%d %d\n", &l, &r);
			l--; r--;
			int ans = -1;
			if (l == r)
				ans = 1;
			else if (ends[arr[l]] == ends[arr[r]])
				ans = r - l + 1;
			else if (l == 0 || l == ends[arr[l - 1]] + 1)
				ans = freq[freqTree.rmq(l, r)];
			else
				ans = max(ends[arr[l]] - l + 1, freq[freqTree.rmq(ends[arr[l]] + 1, r)]);
			printf("%d\n", ans);
		}
	}
	return 0;
}
