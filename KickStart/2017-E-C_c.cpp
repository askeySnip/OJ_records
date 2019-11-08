#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const double eps = 1e-11;
double x[3], y[3], z[3];
struct TP {
  TP() {}
  TP(double _x, double _y) {
    x = _x;
    y = _y;
  }
  double x, y;
} p[10];
struct TC {
  TC() {}
  TC(const TP &a, double _r) { o = a, r = _r; }
  TP o;
  double r;
} circle[3];
double sqr(double x) { return x * x; }
double veclen(int i, int j) {
  return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
}
double dis(TP a, TP b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
int gflag = 0;
void check(TP a) {
  int flag = 1;
  for (int i = 0; i < 3; i++)
    if (!(dis(circle[i].o, a) < circle[i].r + eps)) flag = 0;
  if (flag) gflag = 1;
}
bool cross(TC a, TC b, TP &aa, TP &bb) {
  double ll = dis(a.o, b.o);
  double l = ll * ll;
  if (ll < fabs(a.r - b.r) + eps || ll > a.r + b.r - eps) return false;
  double s = ((a.r - b.r) * (a.r + b.r) / l + 1) * .5;
  double t = sqrt(-(l - sqr(a.r - b.r)) * (l - sqr(a.r + b.r)) / (l * l * 4));
  TP dir = TP(b.o.x - a.o.x, b.o.y - a.o.y), ndir = TP(-dir.y, dir.x);
  aa = TP(a.o.x + dir.x * s + ndir.x * t, a.o.y + dir.y * s + ndir.y * t);
  bb = TP(a.o.x + dir.x * s - ndir.x * t, a.o.y + dir.y * s - ndir.y * t);
  return true;
}
void work(int a, int b, int c, double r) {
  circle[0] = TC(p[0], a * r);
  circle[1] = TC(p[1], b * r);
  circle[2] = TC(p[2], c * r);
  for (int i = 0; i < 3; i++) check(p[i]);
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++) {
      TP p1, p2;
      if (cross(circle[i], circle[j], p1, p2)) {
        check(p1), check(p2);
      }
    }
}
int main() {
  // freopen("c.in", "r", stdin);
  // freopen("c.out", "w", stdout);
  int ca = 0;
  int T;
  for (scanf("%d", &T); T; T--) {
    printf("Case #%d: ", ++ca);
    for (int i = 0; i < 3; i++) {
      scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
    }
    double l1 = veclen(0, 1);
    double l2 = veclen(0, 2);
    double l3 = veclen(1, 2);
    double dot = (x[1] - x[0]) * (x[2] - x[0]) + (y[1] - y[0]) * (y[2] - y[0]) +
                 (z[1] - z[0]) * (z[2] - z[0]);
    // cerr << dot << ' ' << l1 << ' ' << l2 << ' ' << dot / l1 / l2 << endl;
    double ag3 = acos(dot / l1 / l2);
    if (dot / l1 / l2 > 1) ag3 = 0;
    if (dot / l1 / l2 < -1) ag3 = acos(-1.0);
    //	cerr << ag3 << endl;
    p[0] = TP(0, 0);
    p[1] = TP(l1, 0);
    p[2] = TP(cos(ag3) * l2, sin(ag3) * l2);
    while (!(fabs(dis(p[0], p[1]) - l1) < eps &&
             fabs(dis(p[0], p[2]) - l2) < eps &&
             fabs(dis(p[1], p[2]) - l3) < eps))
      cerr << "?" << dis(p[0], p[1]) << ' ' << l1 << ' ' << dis(p[0], p[2])
           << ' ' << l2 << ' ' << dis(p[1], p[2]) << ' ' << l3 << endl;
    double l = 0, r = 10000;
    for (int i = 0; i < 1000; i++) {
      double m = (l + r) / 2.0;
      gflag = 0;
      work(1, 3, 3, m);
      work(3, 1, 3, m);
      work(3, 3, 1, m);
      work(5, 1, 1, m);
      work(1, 5, 1, m);
      work(1, 1, 5, m);
      if (gflag)
        r = m;
      else
        l = m;
    }
    printf("%.10f\n", r);
  }
}
