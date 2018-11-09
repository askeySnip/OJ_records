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
class UnionFind{
private:
  vi p, rank;
public:
  UnionFind(int n) {
    p.assign(n, 0); for(int i=0; i<n; i++) p[i] = i;
    rank.assign(n, 0);
  }
  int findSet(int i) {
    return (i == p[i])? i: (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};
int n, m;
vector<pair<int, ii> > edges;
int main() {
  while(scanf("%d %d", &n, &m), n || m) {
    int u, v, w;
    edges.clear();
    vi ans;
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      edges.push_back(make_pair(w, ii(u, v)));
    }
    UnionFind uf(n);
    sort(edges.begin(), edges.end());
    for(int i=0; i<m; i++) {
      if(uf.isSameSet(edges[i].second.first, edges[i].second.second)) {
        ans.push_back(edges[i].first);
      }
      uf.unionSet(edges[i].second.first, edges[i].second.second);
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) printf("forest\n");
    else {
      for(int i=0; i<(int)ans.size(); i++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
