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

//struct
class UnionFind{
private:
  vi p, rank;
  int size;
public:
  UnionFind(int n) {
    rank.assign(n, 0); p.assign(n, 0);
    for(int i=0; i<n; i++) p[i] = i;
    size = n;
  }
  int findSet(int i) {
    return (i == p[i]) ? i : (p[i] = findSet(p[i]));
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
      size--;
    }
  }
  int setSize() { return size; }
};

// data
int s, p;
vii nodes;
vector<pair<double, ii> > edges;

inline int x2(int x) {
  return x*x;
}
double comp_dist(int i, int j) {
  return sqrt(x2(nodes[i].first - nodes[j].first) + x2(nodes[i].second - nodes[j].second));
}

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    //inital
    nodes.clear();
    edges.clear();
    
    scanf("%d %d", &s, &p);
    int x, y;
    for(int i=0; i<p; i++) {
      scanf("%d %d", &x, &y);
      nodes.push_back(ii(x, y));
    }
    for(int i=0; i<p; i++) {
      for(int j=i+1; j<p; j++) {
        double d = comp_dist(i, j);
        edges.push_back(make_pair(d, ii(i, j)));
      }
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(p);
    double ans = 0;
    for(int i=0; i<(int)edges.size(); i++) {
      if(uf.isSameSet(edges[i].second.first, edges[i].second.second)) continue;
      uf.unionSet(edges[i].second.first, edges[i].second.second);
      if(uf.setSize() == s) {
        ans = edges[i].first;
        break;
      }
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
