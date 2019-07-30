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
vii points;

bool inside(ii& a, ii& b, ii& c) {
  if((a.first == b.first || a.first == c.first) && a.second >= b.second && a.second <= c.second) return true;
  if((a.second == b.second || a.second == c.second) && a.first >= b.first && a.first <= c.first) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cntx[60] = {0}, cnty[60] = {0};
  cin >> n;
  int x, y;
  REP(i, 0, 4 * n + 1) {
    cin >> x >> y;
    points.push_back(ii(x, y));
    cntx[x]++;
    cnty[y]++;
  }
  ii bl = ii(100, 100), tr = ii(0, 0);
  REP(i, 0, 60) {
    if(cntx[i] >= 2) {
      bl.first = min(bl.first, i);
      tr.first = max(tr.first, i);
    }
    if(cnty[i] >= 2) {
      bl.second = min(bl.second, i);
      tr.second = max(tr.second, i);
    }
  }
  REP(i, 0, 4 * n + 1) {
    if(!inside(points[i], bl, tr)) {
      cout << points[i].first << " " << points[i].second << endl;
      return 0;
    }
  }
  return 0;
}
