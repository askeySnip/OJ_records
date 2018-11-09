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
    rank.assign(n, 0); p.assign(n, 0);
    for(int i=0; i<n; i++) p[i] = i;
  }
  int findSet(int i) {
    return (i == p[i])? i:(p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if(!isSameSet(i, j)){
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else {
        p[x] = y;
        if(rank[x]==rank[y]) rank[y]++;
      }
    }
  }
};

int c, s, q;
vector<pair<int, ii> > edges;
vii graph[103];
int dist[103][103];
int vist[103];

void dfs(int root, int v, int m) {
  vist[v] = 1;
  for(int i=0; i<(int)graph[v].size(); i++) {
    int u = graph[v][i].first;
    if(vist[u]) continue;
    if(dist[root][u] == -1){
      dist[root][u] = dist[u][root] = max(m, graph[v][i].second);
    }
    // cout << v << " " << u << " " << max(m, graph[v][i].second) << endl;
    dfs(root, u, max(m, graph[v][i].second));
  }
  vist[v] = 0;
}
int main() {
  int kase = 0;
  while(scanf("%d %d %d", &c, &s, &q), c||s||q) {
    if(kase) printf("\n");
    memset(dist, -1, sizeof dist);
    memset(vist, 0, sizeof vist);
    edges.clear();
    for(int i=0; i<103; i++) graph[i].clear();
    int f, t, d;
    for(int i=0; i<s; i++) {
      scanf("%d %d %d", &f, &t, &d);
      edges.push_back(make_pair(d, ii(f, t)));
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(c+1);
    for(int i=0; i<s; i++){
      int u = edges[i].second.first, v = edges[i].second.second;
      if(uf.isSameSet(u, v)) continue;
      uf.unionSet(u, v);
      graph[u].push_back(ii(v, edges[i].first));
      graph[v].push_back(ii(u, edges[i].first));
    }
    for(int i=1; i<=c; i++) dfs(i, i, 0);

    printf("Case #%d\n", ++kase);
    for(int i=0; i<q; i++) {
      scanf("%d %d", &f, &t);
      if(dist[f][t] != -1) printf("%d\n", dist[f][t]);
      else printf("no path\n");
    }
  }
  return 0;
}
