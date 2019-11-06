/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const ll inf = 1e9;
const int mod = 1e9 + 7;

struct point {
  double x, y, w;
};

int n;
point p[10010];
double sumx[10010];
double sumy[10010];

bool cmpx(point& a, point& b) { return a.x < b.x; }

bool cmpy(point& a, point& b) { return a.y < b.y; }

double solve() {
  sort(p, p + n, cmpx);
  double w_r = 0;
  REP(i, 0, n) { w_r += p[i].w; }
  REP(i, 0, n) sumx[i] = sumy[i] = 0;
  REP(i, 1, n) { sumx[0] = sumx[0] + (p[i].x - p[0].x) * p[i].w; }
  double w_l = 0;
  double tmpx = sumx[0];
  REP(i, 1, n) {
    w_l += p[i - 1].w;
    w_r -= p[i - 1].w;
    sumx[i] =
        sumx[i - 1] + w_l * (p[i].x - p[i - 1].x) - w_r * (p[i].x - p[i - 1].x);
    tmpx = min(sumx[i], tmpx);
  }
  sort(p, p + n, cmpy);
  w_r = 0;
  REP(i, 0, n) { w_r += p[i].w; }
  REP(i, 1, n) { sumy[0] = sumy[0] + (p[i].y - p[0].y) * p[i].w; }
  w_l = 0;
  double tmpy = sumy[0];
  REP(i, 1, n) {
    w_l += p[i - 1].w;
    w_r -= p[i - 1].w;
    sumy[i] =
        sumy[i - 1] + w_l * (p[i].y - p[i - 1].y) - w_r * (p[i].y - p[i - 1].y);
    tmpy = min(sumy[i], tmpy);
  }
  return tmpx + tmpy;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  // t = 1;
  while (t--) {
    scanf("%d", &n);
    double x, y, w;
    REP(i, 0, n) {
      scanf("%lf%lf%lf", &x, &y, &w);
      p[i].x = (x + y) / 2.0;
      p[i].y = (x - y) / 2.0;
      p[i].w = w;
    }
    printf("Case #%d: %.6f\n", ++kase, solve());
    // solve();
  }
  return 0;
}
