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
    p.assign(n, 0); rank.assign(n, 0);
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
  int getSize() { return size; }
};

// data
int n, m;
vector<pair<int, ii> > edges;
vi mst;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    edges.clear();
    mst.clear();

    scanf("%d %d", &n, &m);
    int a, b, c;
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &a, &b, &c);
      edges.push_back(make_pair(c, ii(a, b)));
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(n+1);
    int ans1 = 0, ans2 = 1e9;
    for(int i=0; i<m; i++) {
      if(uf.isSameSet(edges[i].second.first, edges[i].second.second)) continue;
      uf.unionSet(edges[i].second.first, edges[i].second.second);
      mst.push_back(i);
      ans1 += edges[i].first;
    }
    for(int i=0; i<(int)mst.size(); i++) {
      int t = 0;
      UnionFind uf2(n+1);
      for(int j=0; j<m; j++) {
        if(j == mst[i] || uf2.isSameSet(edges[j].second.first, edges[j].second.second)) continue;
        uf2.unionSet(edges[j].second.first, edges[j].second.second);
        t += edges[j].first;
      }
      if(uf2.getSize() == 2) ans2 = min(ans2, t);
    }
    printf("%d %d\n", ans1, ans2);
  }
  return 0;
}
