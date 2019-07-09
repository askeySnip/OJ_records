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
int n, k;
int d, x, y;

int main() {
  scanf("%d %d", &n, &k);
  UnionFind uf(n*3+10);
  int ans = 0;
  REP(i, 0, k) {
    scanf("%d %d %d", &d, &x, &y);
    x--; y--;
    if(x < 0 || y < 0 || x >= n || y >= n) {
      ans++;
      continue;
    }
    if(d == 1) {
      if(uf.isSameSet(x, y+n) || uf.isSameSet(x, y+2*n)) ans++;
      else {
        uf.unionSet(x, y);
        uf.unionSet(x+n, y+n);
        uf.unionSet(x+2*n, y+2*n);
      }
    }
    else {
      if(uf.isSameSet(x, y) || uf.isSameSet(x, y+2*n)) ans++;
      else {
        uf.unionSet(x, y+n);
        uf.unionSet(x+n, y+2*n);
        uf.unionSet(x+2*n, y);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
