/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
struct point {
  double x, y;
  point() {x = y = 0;}
  point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dot(vec a, vec b) {
  return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
  return (v.x * v.x + v.y * v.y);
}

vec scale(vec v, double s) {
  return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
  return point(p.x + v.x, p.y + v.y);
}

double distToLineSegment(point p, point a, point b, point& c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if(u < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if(u > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  c = translate(a, scale(ab, u));
  return dist(p, c);
}

int main() {
  double x, y;
  int n;
  while(scanf("%lf%lf", &x, &y) == 2) {
    point m = point(x, y);
    scanf("%d", &n);
    scanf("%lf%lf", &x, &y);
    point last = point(x, y);
    point ans, tmp;
    double d = 1e9;
    for(int i=0; i<n; i++) {
      scanf("%lf%lf", &x, &y);
      point cur = point(x, y);
      double td = distToLineSegment(m, last, cur, tmp);
      if(td < d) {
        d = td;
        ans = point(tmp.x, tmp.y);
      }
      last = point(cur.x, cur.y);
    }
    printf("%.4f\n%.4f\n", ans.x, ans.y);
  }
  return 0;
}
