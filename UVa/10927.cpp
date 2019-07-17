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

// data
struct point {
  double x, y, z;               // must use double, cause int may overflow.
  double grad, d;
  point() {x = y = z = 0; grad = d = 0;}
  point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {
    if(y != 0) grad = x * 1.0 / y;         // notice : when y = 0
    else grad = x > 0 ? 1e8 : (x == 0 ? 0 : -1e8);
    d = sqrt(x * x + y * y);
  }
  bool operator < (point other) const {
    if(fabs(grad - other.grad) < ESP) {
      return d < other.d;       // cause of y > 0 so d makes the point sort from near (0, 0) to far from
    }
    return grad < other.grad;
  }
};

int main() {
  int n;
  int x, y, z;
  int kase = 0;
  while(scanf("%d", &n), n) {
    vector<point> vp;
    for(int i=0; i<n; i++) {
      scanf("%d%d%d", &x, &y, &z);
      vp.push_back(point(x, y, z));
    }
    sort(vp.begin(), vp.end());
    vii ans;
    int maxh = vp[0].z;
    for(int i=1; i<n; i++) {
      if(fabs(vp[i].grad - vp[i-1].grad) < ESP) {
        if(vp[i].z <= maxh) {
          ans.push_back(ii(vp[i].x, vp[i].y));
        } else {
          maxh = vp[i].z;
        }
      } else {
        maxh = vp[i].z;
      }
    }
    sort(ans.begin(), ans.end());
    printf("Data set %d:\n", ++kase);
    if(ans.size() == 0) {
      printf("All the lights are visible.\n");
    } else {
      printf("Some lights are not visible:\n");
      for(int i=0; i<(int)ans.size(); i++) {
        printf("x = %d, y = %d", ans[i].first, ans[i].second);
        if(i == (int)ans.size() - 1) printf(".\n");
        else printf(";\n");
      }
    }
  }
  return 0;
}
