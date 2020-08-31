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
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

// data
int n;
void left(vi& a) {
  swap(a[2], a[4]);
  swap(a[3], a[5]);
  swap(a[4], a[5]);
}

void down(vi& a) {
  swap(a[0], a[4]);
  swap(a[1], a[5]);
  swap(a[0], a[1]);
}

int main() {
  vi a{1, 2, 3, 4, 5, 6};
  map<vi, int> id;
  int c = 0;
  do {
    id[a] = c++;
  } while (next_permutation(a.begin(), a.end()));
  UnionFind uf(1024);
  int vist[1024];
  memset(vist, 0, sizeof vist);
  do {
    if(vist[id[a]]) continue;
    vist[id[a]] = 1;
    vi t = a;
    for(int i=0; i<3; i++) {
      left(t);
      vist[id[t]] = 1;
      uf.unionSet(id[a], id[t]);
    }
    t = a;
    for(int i=0; i<3; i++) {
      down(t);
      vist[id[t]] = 1;
      uf.unionSet(id[a], id[t]);
    }
    t = a;
    for(int i=0; i<3; i++) {
      left(t);
      vi tt = t;
      for(int i=0; i<3; i++) {
        down(t);
        vist[id[t]] = 1;
        uf.unionSet(id[a], id[t]);
      }
      t = tt;
    }
  } while (next_permutation(a.begin(), a.end()));
  scanf("%d", &n);
  map<int, int> cnt;
  vi m(6, 0);
  REP(i, 0, n) {
    REP(j, 0, 6) scanf("%d", &m[j]);
    ++cnt[uf.findSet(id[m])];
  }
  vi ans;
  for(auto it : cnt) {
    ans.push_back(it.second);
  }
  printf("%d\n", (int)ans.size());
  sort(ans.begin(), ans.end(), greater<int>());
  REP(i,0,ans.size()) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
