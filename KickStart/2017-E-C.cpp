/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const double eps = 1e-12;

// struct
struct point {
  double x, y, z;
};

// data
point p[3];

double sq(double x) { return x * x; }

double dist(point& p1, point& p2) {
  return sqrt(sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z));
}

int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}

bool in_circle(point& p0, point& p1, point& p2, double r0, double r1,
               double r2) {
  double d = dist(p0, p1);
  double a = atan2(p1.y - p0.y, p1.x - p0.x);
  double da = acos((r0 * r0 + d * d - r1 * r1) / (2 * r0 * d));
  double x0 = p0.x + cos(a - da) * r0, y0 = p0.y + sin(a - da) * r0;
  double x1 = p1.x + cos(a + da) * r1, y1 = p1.y + sin(a + da) * r1;
  if (dcmp(sqrt(sq(p2.x - x0) + sq(p2.y - y0)) - r2) != 1) return true;
  if (dcmp(sqrt(sq(p2.x - x1) + sq(p2.y - y1)) - r2) != 1) return true;
  return false;
}

bool have_common1(point& p0, point& p1, point& p2, double r) {
  if (dcmp(dist(p0, p1) - r * 4) == 1 || dcmp(dist(p0, p2) - r * 4) == 1 ||
      dcmp(dist(p1, p2) - r * 6) == 1)
    return false;
  if (dcmp(dist(p0, p1) - r * 2) != 1 || dcmp(dist(p0, p2) - r * 2) != 1)
    return true;
  if (in_circle(p0, p1, p2, r, 3 * r, 3 * r)) return true;
  if (in_circle(p0, p2, p1, r, 3 * r, 3 * r)) return true;
  if (in_circle(p1, p2, p0, 3 * r, 3 * r, r)) return true;
  return false;
}

bool have_common2(point& p0, point& p1, point& p2, double r) {
  if (dcmp(dist(p0, p1) - 6 * r) == 1 || dcmp(dist(p0, p2) - 6 * r) == 1 ||
      dcmp(dist(p1, p2) - 2 * r) == 1)
    return false;
  if (dcmp(dist(p0, p1) - 4 * r) != 1 || dcmp(dist(p0, p2) - 4 * r) != 1)
    return true;
  if (in_circle(p0, p1, p2, 5 * r, r, r)) return true;
  if (in_circle(p0, p2, p1, 5 * r, r, r)) return true;
  if (in_circle(p1, p2, p0, r, r, 5 * r)) return true;
  return false;
}

bool check(double r) {
  // check if exist a case for type1(each point in a circle)
  if (have_common1(p[0], p[1], p[2], r)) return true;
  if (have_common1(p[1], p[0], p[2], r)) return true;
  if (have_common1(p[2], p[0], p[1], r)) return true;
  // check if exist a case for type2(a circle with 2 point, a circle with none,
  // a cirle with 1)
  if (have_common2(p[0], p[1], p[2], r)) return true;
  if (have_common2(p[1], p[0], p[2], r)) return true;
  if (have_common2(p[2], p[0], p[1], r)) return true;
  return false;
}

double solve() {
  // transfor to xy plane
  double a = dist(p[0], p[1]), b = dist(p[0], p[2]), c = dist(p[1], p[2]);
  p[0].x = p[0].y = p[0].z = 0.0;
  p[1].x = a;
  p[1].y = p[1].z = 0;
  p[2].x = (sq(a) + sq(b) - sq(c)) / (2 * a);
  p[2].y = sqrt(sq(b) - sq(p[2].x));
  p[2].z = 0;
  // binary search to find the minimum R
  double l = 0, r = 10000, mid;
  while (r - l > eps) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  return l;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    REP(i, 0, 3) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
    printf("Case #%d: %.10f\n", ++kase, solve());
  }
  return 0;
}
