/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct
class UnionFind {
 private:
  vi p, rank, sz;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    sz.assign(n, 1);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        sz[x] += sz[y];
      } else {
        p[x] = y;
        sz[y] += sz[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int getSize(int i) { return sz[i]; }
};

// data
int n;


void solve() {
  int t, e, s;
  vector<tuple<int, int, int>> v;
  int ans = 0, id = -1;
  int sum = 0;
  REP(i, 0, n) {
    scanf("%d %d %d", &t, &e, &s);
    if(s == 0) v.emplace_back(t, e, 0);
    else {
      int tt, te, ts;
      tie(tt, te, ts) = v.back();
      if(ans < t - tt - ts) {
        ans = t - tt - ts;
        id = te;
      } else if(ans == t - tt - ts && id > te) {
        id = te;
      }
      v.pop_back();
      if(v.empty()) continue;
      int ttt = t - tt;
      tie(tt, te, ts) = v.back();
      v.pop_back();
      v.emplace_back(tt, te, ts + ttt);
    }
  }
  // cout << ans << endl;
  printf("%d\n", id);
}

int main() {
  int t;
  scanf("%d", &t);
  // t = 1;
  while (t--) {
    scanf("%d", &n);
    solve();
  }
  return 0;
}
