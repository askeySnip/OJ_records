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
#define ESP 1e-15               // 1e-9 is not match the need.

// data
struct point {
  double x, y;
  point() {x = y = 0.0;}
  point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point a, point b) {
  return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

bool inCircle(point p, point c, double r){
  double d = dist(p, c);
  if(fabs(d - r) < ESP) return true;
  if(r < d) return false;
  return true;
}

int main() {
  int n, a, c;
  double x, y;
  while(scanf("%d%d", &n, &a), n) {
    c = 0;
    point p1 = point(0, 0), p2 = point(0, a), p3 = point(a, 0), p4 = point(a, a);
    for(int i=0; i<n; i++) {
      scanf("%lf%lf", &x, &y);
      point t = point(x, y);
      if(inCircle(t, p1, a) && inCircle(t, p2, a) && inCircle(t, p3, a) && inCircle(t, p4, a)) c++;
    }
    printf("%.5f\n", c * a * a * 1.0 / n);
  }
  return 0;
}
