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
  vi p, rank, sz;
  ll ans;
public:
  UnionFind(int n) {
    ans = 0;
    p.assign(n, 0); rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
    sz.assign(n, 1);
  }
  int findSet(int i) {
    return (i == p[i] ? i : p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void uionSet(int i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) {
        p[y] = x;
        ans -= (ll)sz[x] * (sz[x] - 1) / 2;
        sz[x] += sz[y];
        ans -= (ll)sz[y] * (sz[y] - 1) / 2;
        ans += (ll)sz[x] * (sz[x] - 1) / 2;
      } else {
        p[x] = y;
        ans -= (ll)sz[y] * (sz[y] - 1) / 2;
        sz[y] += sz[x];
        ans -= (ll)sz[x] * (sz[x] - 1) / 2;
        ans += (ll)sz[y] * (sz[y] - 1) / 2;
        if(rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
  }
  ll getAns() {
    return ans;
  }
};
// data
int n, m;
vector<pair<int, ii> > e;
vii queries;

bool cmp(pair<int, ii> a, pair<int, ii> b) {
  return a.first < b.first;
}

void solve() {
  UnionFind uf(n+1);
  vector<ll> ans(m);
  int cur = 0;
  REP(i, 0, m) {
    ii p = queries[i];
    while(cur < n-1 && e[cur].first <= p.first) {
      uf.uionSet(e[cur].second.first, e[cur].second.second);
      cur++;
    }
    ans[p.second] = uf.getAns();
  }
  REP(i, 0, m) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int u, v, w;
  REP(i, 1, n) {
    cin >> u >> v >> w;
    e.push_back(make_pair(w, ii(u, v)));
  }
  sort(e.begin(), e.end(), cmp);
  int q;
  REP(i, 0, m) {
    cin >> q;
    //int ed = upper_bound(e.begin(), e.end(), make_pair(q, ii(n, n))) - e.begin();
    //solve(ed);
    queries.push_back(ii(q, i));
  }
  sort(queries.begin(), queries.end());
  solve();
  return 0;
}
