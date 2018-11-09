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
int n, m, s, t;
vii edges[20024];
vi dis;

int main() {
  int N;
  scanf("%d", &N);
  for(int kase = 1; kase <= N; kase ++) {
    for(int i=0; i<20024; i++) edges[i].clear();
    scanf("%d%d%d%d", &n, &m, &s, &t);
    dis.assign(n+1, inf);
    int a, b, c;
    for(int i=0; i<m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      edges[a].push_back(ii(b, c));
      edges[b].push_back(ii(a, c));
    }
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, s));
    while(!pq.empty()) {
      ii p = pq.top(); pq.pop();
      if(dis[p.second] != inf) continue;
      dis[p.second] = p.first;
      if(p.second == t) break;
      for(int i=0; i<(int)edges[p.second].size(); i++) {
        int v = edges[p.second][i].first;
        if(dis[v] == inf) pq.push(ii(p.first + edges[p.second][i].second, v));
      }
    }
    if(dis[t] == inf) printf("Case #%d: unreachable\n", kase);
    else printf("Case #%d: %d\n", kase, dis[t]);
  }
  return 0;
}
