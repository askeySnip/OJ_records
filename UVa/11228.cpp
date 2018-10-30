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
int n, r;
vii nodes;
vector<pair<double, ii> > edges;
inline double square(int x) {
  return x * x;
}
inline double compt_dis(int i, int j) {
  return sqrt(square(nodes[i].first - nodes[j].first) + square(nodes[i].second-nodes[j].second));
}
class UnionFind{
private:
  vi p, rank;
public:
  UnionFind(int n) {
    rank.assign(n, 0); p.resize(n);
    for(int i=0; i<n; i++) p[i] = i;
  }
  int findSet(int i) {
    return (i==p[i])? i: (p[i] = findSet(p[i]));
  }
  int isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void UnionSet(int i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int CountSets() {
    int c = 0;
    for(int i=0; i<n; i++) {
      if(i == p[i]) c++;
    }
    return c;
  }
};
int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    nodes.clear();
    edges.clear();
    scanf("%d %d", &n, &r);
    int x, y;
    UnionFind uf(n);
    for(int i=0; i<n; i++) {
      scanf("%d %d", &x, &y);
      nodes.push_back(ii(x, y));
    }
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        double dis = compt_dis(i, j);
        edges.push_back(make_pair(dis, ii(i, j)));
        if(dis <= r) uf.UnionSet(i, j);
      }
    }

    sort(edges.begin(), edges.end());
    UnionFind uf2(n);
    double roads = 0, rail = 0;
    for(int i=0; i<(int)edges.size(); i++) {
      if(uf2.isSameSet(edges[i].second.first, edges[i].second.second)) continue;
      uf2.UnionSet(edges[i].second.first, edges[i].second.second);
      if(edges[i].first > r) rail += edges[i].first;
      else roads += edges[i].first;
    }

    printf("Case #%d: %d %d %d\n", ++kase, uf.CountSets(), (int)(roads+0.5), (int)(rail+0.5));
  }
  return 0;
}
