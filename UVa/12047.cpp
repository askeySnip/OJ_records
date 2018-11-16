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

// struct
#define inf 1e9

// data
int n, m, s, t, p;
vii edges[10003], re_edges[10003];
vi d1, d2;
vector<pair<ii, int> > eg;

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
    for(int i=0; i<10003; i++) {edges[i].clear(); re_edges[i].clear();}
    eg.clear();
    d1.assign(n+1, inf); d2.assign(n+1, inf);
    int u, v, c;
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &u, &v, &c);
      edges[u].push_back(ii(v, c));
      re_edges[v].push_back(ii(u, c));
      eg.push_back(make_pair(ii(u, v), c));
    }
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, s));
    while(!pq.empty()) {
      ii p = pq.top(); pq.pop();
      if(d1[p.second] != inf) continue;
      d1[p.second] = p.first;
      for(int i=0; i<(int)edges[p.second].size(); i++) {
        int v = edges[p.second][i].first;
        if(d1[v] == inf) pq.push(ii(p.first + edges[p.second][i].second, v));
      }
    }
    pq.push(ii(0, t));
    while(!pq.empty()) {
      ii p = pq.top(); pq.pop();
      if(d2[p.second] != inf) continue;
      d2[p.second] = p.first;
      for(int i=0; i<(int)re_edges[p.second].size(); i++) {
        int v = re_edges[p.second][i].first;
        if(d2[v] == inf) pq.push(ii(p.first + re_edges[p.second][i].second, v));
      }
    }
    if(d1[t] == inf) {printf("-1\n");}
    else{
      int ans = -1;
      for(int i=0; i<(int)eg.size(); i++) {
        if(d1[eg[i].first.first] + eg[i].second + d2[eg[i].first.second] <= p) {
          ans = max(ans, eg[i].second);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
