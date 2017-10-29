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

#define SQUARE 5
#define RECTANGLE 4
#define RHOMBUS 3
#define PARALLELOGRAM 2
#define TRAPEZIUM 1
#define ORDINARY 0

struct point { int x, y;     // whenever possible, work with point_i
  point() { x = y = 0; }                      // default constructor
  point(int _x, int _y) : x(_x), y(_y) {}            // user-defined
  
  bool operator<(point other)
  {
	  if (this->x == other.x) return this->y < other.y;
	  return this->x < other.x;
  }
};

bool distEqual(point a1, point a2, point b1, point b2)
{
	return (a1.x - a2.x)*(a1.x - a2.x) + (a1.y - a2.y)*(a1.y - a2.y) == (b1.x - b2.x)*(b1.x - b2.x) + (b1.y - b2.y)*(b1.y - b2.y);
}

bool areParallel(point a1, point a2, point b1, point b2)
{
	point A1 = (a1.x < a2.x) ? a1 : a2;
	point A2 = (a1.x < a2.x) ? a2 : a1;
	point B1 = (b1.x < b2.x) ? b1 : b2;
	point B2 = (b1.x < b2.x) ? b2 : b1;
	if (A1.x == A2.x || B1.x == B2.x)
		return A1.x == A2.x && B1.x == B2.x;
	return ((ll)((ll)(A1.y - A2.y) * INF*INF) / (ll)(A1.x - A2.x) == (ll)((ll)(B1.y - B2.y) * INF*INF) / (ll)(B1.x - B2.x));
}

bool arePerpendicular(point a1, point a2, point b1, point b2)
{
	point A1 = (a1.x < a2.x) ? a1 : a2;
	point A2 = (a1.x < a2.x) ? a2 : a1;
	point B1 = (b1.x < b2.x) ? b1 : b2;
	point B2 = (b1.x < b2.x) ? b2 : b1;
	if (a1.x == a2.x || b1.x == b2.x || a1.y == a2.y || b1.y == b2.y)
		return (a1.x == a2.x && b1.y == b2.y) || (a1.y == a2.y && b1.x == b2.x);
	ll aslope = (ll)((ll)(a1.y - a2.y) * INF*INF) / (ll)(a1.x - a2.x);
	ll bslope = (ll)((ll)(b1.x - b2.x) * -INF*INF) / (ll)(b1.y - b2.y);
	return (aslope == bslope);
}

int main()
{
	int T; scanf("%d\n", &T);
	int caseno = 0;
	while (T--)
	{
		vector<point> points;
		for (int i = 0; i < 4; ++i)
		{
			int x, y;
			scanf("%d %d\n", &x, &y);
			points.push_back(point(x, y));
		}
		// try each permutation of points, check if shape
		int shape = 0;
		for (int i = 0; i < 24; ++i)
		{
			bool sidesEqual = distEqual(points[0], points[1], points[2], points[3]) && distEqual(points[0], points[1], points[3], points[0]);
			bool parallelSides = areParallel(points[0], points[1], points[2], points[3]) && areParallel(points[1], points[2], points[3], points[0]);
			bool oneParallelPair = areParallel(points[0], points[1], points[2], points[3]) || areParallel(points[1], points[2], points[3], points[0]);
			bool rightAngleSides = arePerpendicular(points[0], points[1], points[1], points[2]) && arePerpendicular(points[0], points[1], points[3], points[0]) && arePerpendicular(points[1], points[2], points[2], points[3]);
			// printf("%d%d%d%d\n", sidesEqual, parallelSides, oneParallelPair, rightAngleSides);
			int curshape = ORDINARY;
			if (sidesEqual)
				curshape = rightAngleSides ? SQUARE : parallelSides ? RHOMBUS : ORDINARY;
			else if (rightAngleSides)
				curshape = RECTANGLE;
			else if (parallelSides)
				curshape = PARALLELOGRAM;
			else if (oneParallelPair)
				curshape = TRAPEZIUM;
			shape = max(shape, curshape);
			
			next_permutation(points.begin(), points.end());
		}
		string shapes[6] = {"Ordinary Quadrilateral", "Trapezium", "Parallelogram", "Rhombus", "Rectangle", "Square"};
		printf("Case %d: %s\n", ++caseno, shapes[shape].c_str());
	}
	return 0;
}
