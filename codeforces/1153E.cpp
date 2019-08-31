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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n;
vii ans;

void getOne(int x1, int y1, int x2, int y2) {
  int t;
  if(x1 == x2) {
    while(y1 < y2) {
      int y_m = (y1 + y2) / 2;
      printf("? %d %d %d %d\n", x1, y1, x2, y_m);
      fflush(stdout);
      scanf("%d", &t);
      if(t%2) y2 = y_m;
      else y1 = y_m + 1;
    }
  } else {
    while(x1 < x2) {
      int x_m = (x1 + x2) / 2;
      printf("? %d %d %d %d\n", x1, y1, x_m, y2);
      fflush(stdout);
      scanf("%d", &t);
      if(t%2) x2 = x_m;
      else x1 = x_m + 1;
    }
  }
  ans.push_back(ii(x1, y1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  scanf("%d", &n);
  int t;
  if(n * n == 2019) {
    REP(i, 1, n+1) {
      REP(j, 1, n+1) {
        printf("? %d %d %d %d\n", i, j, i, j);
        fflush(stdout);
        scanf("%d", &t);
        if(t == 1) ans.push_back(ii(i, j));
      }
    }
    printf("! %d %d %d %d\n", ans[0].first, ans[0].second, ans[1].first, ans[1].second);
  } else {
    bool f = false;
    REP(i, 1, n) {
      printf("? %d %d %d %d\n", i, 1, i, n);
      fflush(stdout);
      scanf("%d", &t);
      if(t%2) getOne(i, 1, i, n), f = !f;
    }
    if(f) getOne(n, 1, n, n);
    if(ans.size() == 2) {
      printf("! %d %d %d %d\n", ans[0].first, ans[0].second, ans[1].first, ans[1].second);
      return 0;
    }
    f = false;
    REP(i, 1, n) {
      printf("? %d %d %d %d\n", 1, i, n, i);
      fflush(stdout);
      scanf("%d", &t);
      if(t%2) {
        if(!f) getOne(1, i, n, i);
        else  {
          ans.push_back(ii(ans.back().first, i));
        }
        f = !f;
      }
    }
    if(f) ans.push_back(ii(ans.back().first, n));
    printf("! %d %d %d %d\n", ans[0].first, ans[0].second, ans[1].first, ans[1].second);
  }
  return 0;
}
