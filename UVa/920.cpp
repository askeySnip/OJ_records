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
  int x, y;
  point() {x = y = 0;}
  point(int _x, int _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if(x == other.x) return y < other.y;
    return x < other.x;
  }
};

double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  int c, n, x, y;
  scanf("%d", &c);
  for(int kase=0; kase<c; kase++) {
    scanf("%d", &n);
    vector<point> vp;
    for(int i=0; i<n; i++) {
      scanf("%d %d", &x, &y);
      vp.push_back(point(x, y));
    }
    sort(vp.begin(), vp.end());
    double ans = 0;
    int maxy = 0;
    for(int i=vp.size()-1; i>=0; i--) {
      if(vp[i].y <= maxy) continue;
      ans += (dist(vp[i], vp[i+1]) * (vp[i].y - maxy) * 1.0 / (vp[i].y - vp[i+1].y));
      maxy = vp[i].y;
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
