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
struct rectangle {
  int xbl, ybl, xtr, ytr;
};
// data

bool intersect(rectangle& a, rectangle& b) {
  int xbl = max(a.xbl, b.xbl);
  int ybl = max(a.ybl, b.ybl);
  int xtr = min(a.xtr, b.xtr);
  int ytr = min(a.ytr, b.ytr);
  if(xbl > xtr || ybl > ytr) return false;
  a.xbl = xbl, a.ybl = ybl, a.xtr = xtr, a.ytr = ytr;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, n;
  cin >> q;
  while(q--) {
    cin >> n;
    int x, y, f1, f2, f3, f4;
    rectangle cur;
    bool f = true;
    cur.xbl = cur.ybl = -100000;
    cur.xtr = cur.ytr = 100000;
    REP(i, 0, n) {
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      if(!f) continue;
      rectangle r;
      if(f1) r.xbl = -100000;
      else r.xbl = x;
      if(f2) r.ytr = 100000;
      else r.ytr = y;
      if(f3) r.xtr = 100000;
      else r.xtr = x;
      if(f4) r.ybl = -100000;
      else r.ybl = y;
      f = intersect(cur, r);
    }
    if(f) {
      cout << "1 " << cur.xbl << " " << cur.ybl << endl;
    } else {
      cout << "0" << endl;
    }
  }
  return 0;
}
