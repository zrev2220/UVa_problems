#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

struct point { int x, y;     // whenever possible, work with point_i
  point() { x = y = 0; }                      // default constructor
  point(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

bool distEqual(point a1, point a2, point b1, point b2)
{
	return (abs(a1.x - a2.x) == abs(b1.x - b2.x)) && (abs(a1.y - a2.y) == abs(b1.y - b2.y));
}

bool areParallel(point a1, point a2, point b1, point b2)
{
	point A1 = (a1.x < a2.x) ? a1 : (a1.y < a2.y) ? : a2;
	return (A1.x == A2.x && B1.x == B2.x) ||
		   (A1.y == A2.y && B1.y == B2.y) ||
		   ((long)((long)(A1.y - A2.y) * INF*INF) / (long)(A1.x - A2.x) == (long)((long)(B1.y - B2.y) * INF*INF) / (long)(B1.x - B2.x));
}

bool arePerpendicular(point a1, point a2, point b1, point b2)
{
	return (a1.x == a2.x && b1.y == b2.y) ||
		   (a1.y == a2.y && b1.x == b2.x) ||
		   ((long)((long)(a1.y - a2.y)) / (long)(a1.x - a2.x) == (long)((long)(b1.y - b2.y) * -INF*INF) / (long)(b1.x - b2.x));
}

int main()
{
	// int T; scanf("%d\n", &T);
	int caseno = 1;
	/* 1 */printf("%d\n", distEqual(point(-2, 0), point(0, 2), point(-1, -1), point(1, 1)));
	/* 0 */printf("%d\n", distEqual(point(-2, 0), point(0, 2), point(0, 0), point(1, 1)));
	/* 0 */printf("%d\n", areParallel(point(1000000000, 1000000000), point(-1000000000, -1000000000), point(-1000000000, -1000000000), point(1000000000, 1000000001)));
	/* 1 */printf("%d\n", areParallel(point(-2, 0), point(0, 2), point(0, 0), point(1, 1)));
	/* 1 */printf("%d\n", arePerpendicular(point(-2, 0), point(0, 2), point(2, 0), point(1, 1)));
	/* 0 */printf("%d\n", arePerpendicular(point(1000000000, 1000000000), point(-1000000000, -1000000000), point(-1000000000, 1000000000), point(1000000000, -1000000001)));
	/* 1 */printf("%d\n", arePerpendicular(point(1000000000, 1000000000), point(-1000000000, -1000000000), point(-1000000000, 1000000000), point(1000000000, -1000000000)));
	// while (T--)
	// {
		// vector<point> points;
		// for (int i = 0; i < 4; ++i)
		// {
			// point pt;
			// scanf("%d %d\n", pt.x, pt.y);
			// points.push_back(pt);
		// }
		//// try each permutation of points, check if shape
		// int shape = 0;
		// for (int i = 0; i < 24; ++i)
		// {


			// next_permutation(points.begin(), points.end());
		// }
		// string shapes[6] = {"Ordinary Quadrilateral", "Trapezium", "Parallelogram", "Rhombus", "Rectangle", "Square"};
		// printf("Case %d: %s\n", caseno++, shapes[shape].c_str());
	// }
	return 0;
}
