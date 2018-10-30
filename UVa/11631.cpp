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
int m, n;
vector<pair<int, ii> > edges;
class UnionFind{
private:
  vi p, rank;
public:
  UnionFind(int n) {
    p.assign(n, 0); rank.assign(n, 0);
    for(int i=0; i<n; i++) p[i] = i;
  }
  int findSet(int i) {
    return (i == p[i])? i:(p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void UnionSet(int i, int j) {
    if(!isSameSet(i, j)){
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};
int main() {
  while(scanf("%d %d", &m, &n), m || n) {
    edges.clear();
    int tot = 0;
    for(int i=0; i<n; i++) {
      int f, t, d;
      scanf("%d %d %d", &f, &t, &d);
      edges.push_back(make_pair(d, ii(f, t)));
      tot+=d;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(m);
    int act = 0;
    for(int i=0; i<n; i++) {
      if(uf.isSameSet(edges[i].second.first, edges[i].second.second)) continue;
      uf.UnionSet(edges[i].second.first, edges[i].second.second);
      act += edges[i].first;
    }
    printf("%d\n", tot-act);
  }
  return 0;
}
