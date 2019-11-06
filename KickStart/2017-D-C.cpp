/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e15
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const double eps = 1e-12;

struct point {
  double x, y;
  point() : x(0), y(0) {}
  point(double _x, double _y) : x(_x), y(_y) {}
};

double sq(double x) { return x * x; }

// data
int n;
double p, h;
point obs[12];

double dis(double a, double x, point& o) {
  return sqrt(sq(x - o.x) + sq(a * x * (x - p) - o.y));
}

double search_r(double a, point& o) {
  double l = 0.0, r = p;
  if (o.x >= p / 2.0)
    l = p / 2.0;
  else
    r = p / 2.0;

  while (r - l > eps) {
    double mid0 = (l + l + r) / 3.0;
    double mid1 = (l + r + r) / 3.0;
    double val0 = dis(a, mid0, o);
    double val1 = dis(a, mid1, o);
    if (val0 > val1) {
      l = mid0;
    } else {
      r = mid1;
    }
  }
  return dis(a, l, o);
}

double func_min(double a) {
  double ret = inf;
  REP(i, 0, n) { ret = min(ret, search_r(a, obs[i])); }
  ret = min(ret, h + sq(p) * a / 4.0);
  return ret;
}

double calc(int mask) {
  double a_high = 0;
  double a_low = -4.0 * h / sq(p);
  REP(i, 0, n) {
    double a_mid = obs[i].y / (obs[i].x * (obs[i].x - p));
    if (mask & (1 << i)) {  // fly above the ith obs
      a_high = min(a_high, a_mid);
    } else {
      a_low = max(a_low, a_mid);
    }
  }
  if (a_low >= a_high) return 0.0;

  while (a_high - a_low > eps) {
    double mid0 = (a_high + a_low + a_low) / 3;
    double mid1 = (a_high + a_high + a_low) / 3;
    double val0 = func_min(mid0);
    double val1 = func_min(mid1);
    if (val0 > val1) {
      a_high = mid1;
    } else {
      a_low = mid0;
    }
  }

  return func_min(a_low);
}

double solve() {
  double ans = 0;
  REP(i, 0, (1 << n)) {
    double tmp = calc(i);
    ans = max(ans, tmp);
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%lf%lf", &n, &p, &h);
    REP(i, 0, n) scanf("%lf%lf", &obs[i].x, &obs[i].y);
    printf("Case #%d: %.11f\n", ++kase, solve());
  }

  return 0;
}
