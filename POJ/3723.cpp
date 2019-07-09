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

class UnionFind{
private:
  vi p, rank;
public:
  UnionFind(int n) {
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
  }
  int findSet(int i) {
    return (i == p[i] ? i : p[i] = findSet(p[i]));
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
// data
int n, m, r;
vector<pair<int, ii> > edges;

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    edges.clear();
    scanf("%d %d %d", &n, &m, &r);
    int x, y, d;
    REP(i, 0, r) {
      scanf("%d %d %d", &x, &y, &d);
      edges.push_back(make_pair(-d, ii(x, y)));
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(n + m);
    int ans = 0;
    REP(i, 0, r) {
      int a = edges[i].second.first, b = edges[i].second.second + n;
      if(!uf.isSameSet(a, b)) {
        ans += edges[i].first;
        uf.unionSet(a, b);
      }
    }
    printf("%d\n", 10000*(n+m)+ans);
  }
  return 0;
}
