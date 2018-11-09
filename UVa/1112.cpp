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
int n, m, e, T;
vii edges[102];
vi dis;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i=0; i<102; i++) edges[i].clear();
    scanf("%d%d%d%d", &n, &e, &T, &m);
    dis.assign(n+1, inf);
    int a, b, v;
    for(int i=0; i<m; i++) {
      scanf("%d%d%d", &a, &b, &v);
      edges[b].push_back(ii(a, v));
    }
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(e, 0));
    while(!pq.empty()) {
      ii p = pq.top(); pq.pop();
      if(dis[p.first] != inf) continue;
      dis[p.first] = p.second;
      for(int i=0; i<(int)edges[p.first].size(); i++) {
        int v = edges[p.first][i].first;
        if(dis[v] == inf) pq.push(ii(v, p.second + edges[p.first][i].second));
      }
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
      // cout << dis[i] << " " << endl;
      if(dis[i] <= T) ans++;
    }
    printf("%d\n", ans);
    if(t) printf("\n");
  }
  return 0;
}
