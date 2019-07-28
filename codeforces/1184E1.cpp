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
class UnionFind {
private:
  vi p, rank;
public:
  UnionFind(int n) {
    p.assign(n, 0); rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) {
    return i == p[i] ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};
struct eg {
  int da, db, e;
  eg(int _da, int _db, int _e) {
    da = _da, db = _db, e = _e;
  }
  bool operator == (eg other) const {
    if(da == other.da && db == other.db && e == other.e) return true;
    return false;
  }
};
// data
const int maxn = 1000024;
int n, m;
int a[maxn], b[maxn], e[maxn];
vector<eg> edges;

bool cmp(eg a, eg b) {
  return a.e < b.e;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  REP(i, 0, m) {
    cin >> a[i] >> b[i] >> e[i];
  }

  REP(i, 0, m) {
    edges.push_back(eg(a[i],b[i],e[i]));
  }
  sort(edges.begin(), edges.end(), cmp);
  // first check if a[0], b[0] is must include
  UnionFind uf1(n + 3);
  int cnt = 0;
  ll val1 = 0L;
  for(int i=0; i<m; i++) {
    int sp = edges[i].da, ep = edges[i].db;
    if(sp == a[0] && ep == b[0]) continue;
    if(!uf1.isSameSet(sp, ep)) {
      uf1.unionSet(sp, ep);
      cnt++;
      val1 += edges[i].e;
    }
  }
  // if edge count < n - 1 then a[0], b[0] is neccessory, then can set the e to the max.
  if(cnt < n - 1) {
    cout << "1000000000" << endl;
    return 0;
  }
  // check the wheter the MST include the a[0], b[0], && store the MST val;
  UnionFind uf(n+3);
  ll val = 0L;
  bool flag = false;
  for(int i=0; i<m; i++) {
    int sp = edges[i].da, ep = edges[i].db;
    if(!uf.isSameSet(sp, ep)) {
      if(sp == a[0] && ep == b[0]) flag = true;
      val += edges[i].e;
      uf.unionSet(sp, ep);
    }
  }
  // union a[0], b[0] fist with e = 0 to get the MST val;
  UnionFind uf2(n+3);
  ll val2 = 0L;
  uf2.unionSet(a[0], b[0]);
  for(int i=0; i<m; i++) {
    int sp = edges[i].da, ep = edges[i].db;
    if(!uf2.isSameSet(sp, ep)) {
      val2 += edges[i].e;
      uf2.unionSet(sp, ep);
    }
  }
  // if MST include the a[0], b[0], then the ans is val1 - val2, else the ans is val - val2;
  if(flag) cout << val1 - val2 << endl;
  else cout << val - val2 << endl;
  return 0;
}
