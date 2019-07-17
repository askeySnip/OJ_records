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
#define ESP 1e-9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
struct point {
  double x, y;
  point () {x = y = 0;}
  point (double _x, double _y) : x(_x), y(_y) {}
};

bool circle2PtsRad(point a, point b, double r, point&c1, point&c2) {
  double d2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  double det = r * r / d2 - 0.25;
  if(det < 0.0) return false;
  double h = sqrt(det);
  c1.x = (a.x + b.x) * 0.5 + (a.y - b.y) * h;
  c1.y = (a.y + b.y) * 0.5 + (b.x - a.x) * h;
  c2.x = (a.x + b.x) * 0.5 + (b.y - a.y) * h;
  c2.y = (a.y + b.y) * 0.5 + (a.x - b.x) * h;
  return true;
}

double dist(point a, point b) {
  return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

bool check(point& c1, vector<point>& vp, double r) {
  for(int i=0; i<(int)vp.size(); i++) {
    double d = dist(c1, vp[i]);
    if(fabs(r - d) < ESP) continue;
    if(r < d) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  double x, y;
  double r;
  while(scanf("%d", &n), n) {
    vector<point> vp;
    for(int i=0; i<n; i++) {
      scanf("%lf%lf", &x, &y);
      vp.push_back(point(x, y));
    }
    scanf("%lf", &r);
    point c1, c2;
    bool ans = false, flag = false;
    for(int i=0; i<n-1; i++) {
      if(flag) break;
      for(int j=i+1; j<n; j++) {
        bool f = circle2PtsRad(vp[i], vp[j], r, c1, c2);
        if(!f) {
          flag = true;
          ans = false;
          break;
        }
        if(check(c1, vp, r) || check(c2, vp, r)) {
          flag = true;
          ans = true;
          break;
        }
      }
    }
    if(!ans) printf("There is no way of packing that polygon.\n");
    else printf("The polygon can be packed in the circle.\n");
  }
  return 0;
}
