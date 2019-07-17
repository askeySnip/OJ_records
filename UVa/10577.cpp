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
#define ESP 1e-9

struct point {
  double x, y;
  point() {x = y = 0.0;}
  point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
  double a, b, c;
};

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

// data


point rotate(point p, double theta, point c) {
  point pp = point(p.x - c.x, p.y - c.y);
  double rad = theta * acos(0) / 90;
  point tp = point(pp.x * cos(rad) - pp.y * sin(rad), pp.x * sin(rad) + pp.y *cos(rad));
  return point(tp.x + c.x, tp.y + c.y);
}

vec point2Vec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

void pointToLine(point p1, point p2, line& l) {
  if(fabs(p1.x - p2.x) < ESP) {
    l.a = 1.0; l.b = 0; l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

void getLine(point p1, point p2, line& l) {
  point m = point((p1.x + p2.x)/2.0, (p1.y + p2.y)/2.0);
  point m_o = rotate(p1, 90.0, m);
  pointToLine(m, m_o, l);
}

void InsertPoint(line l1, line l2, point& p) {
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if(fabs(l1.b) > ESP) p.y = -(l1.a * p.x + l1.c);
  else p.y = -(l2.a * p.x + l2.c);
}

int main() {
  int n;
  double x, y;
  int kase = 0;
  while(scanf("%d", &n), n) {
    vector<point> vp;
    for(int i=0; i<3; i++) {
      scanf("%lf%lf", &x, &y);
      vp.push_back(point(x, y));
    }
    line line1, line2;
    getLine(vp[0], vp[1], line1);
    getLine(vp[0], vp[2], line2);
    point c;
    InsertPoint(line1, line2, c);
    double theta = 360.0 / n;
    double max_x = vp[0].x, max_y=vp[0].y, min_x=vp[0].x, min_y=vp[0].y;
    for(int i=1; i<n; i++) {
      point tmp = rotate(vp[0], theta * i, c);
      max_x = max(max_x, tmp.x);
      max_y = max(max_y, tmp.y);
      min_x = min(min_x, tmp.x);
      min_y = min(min_y, tmp.y);
    }
    printf("Polygon %d: %.3f\n", ++kase, (max_x - min_x) * (max_y - min_y));
  }
  return 0;
}
