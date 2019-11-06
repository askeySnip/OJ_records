/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0), rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

int v, e;
ii neibor[60];
ii zero;

ll solve() {
  UnionFind uf(v + 1);
  int n = v;
  for (int i = 1; i <= v; i++) {
    if (!uf.isSameSet(i, neibor[i].first)) {
      uf.unionSet(i, neibor[i].first);
      n--;
    }
  }
  // cout << n << endl;
  if (zero.first != -1) {
    for (int i = 1; i <= v; i++) {
      if (i != zero.first && i != zero.second &&
          (neibor[i].first == zero.first || neibor[i].first == zero.second))
        n++;
    }
  }
  return (1LL << n);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int a, b, l;
  while (t--) {
    scanf("%d%d", &v, &e);
    for (int i = 1; i <= v; i++) {
      neibor[i].first = 0;
      neibor[i].second = inf;
    }
    zero.first = zero.second = -1;
    REP(i, 0, e) {
      scanf("%d%d%d", &a, &b, &l);
      if (neibor[a].second > l) {
        neibor[a].first = b;
        neibor[a].second = l;
      }
      if (neibor[b].second > l) {
        neibor[b].first = a;
        neibor[b].second = l;
      }
      if (l == 0) {
        zero.first = a;
        zero.second = b;
      }
    }
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
