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


// data
int n;
int node_value[103];
vi edges[103];
vi dist;
int vist[103];
bool flag;

bool bfs(int u) {
  queue<int> q;
  q.push(u);
  memset(vist, 0, sizeof vist);

  while(!q.empty()) {
    u = q.front();
    q.pop();
    if(vist[u]) continue;
    vist[u] = 1;
    if(u == n) return true;
    for(int i=0; i<(int)edges[u].size(); i++) {
      int v = edges[u][i];
      if(!vist[v]) q.push(v);
    }
  }
  return false;
}

void dfs(int s) {
  if(flag) return;
  if(s == n && dist[s] > 0) {
    flag = true;
    return;
  }

  for(int i=0; i<(int)edges[s].size(); i++) {
    int v = edges[s][i];
    if(dist[v] && dist[s] + node_value[v] > dist[v]) {
      flag |= bfs(v);
      if(flag) return;
    }
    if(!dist[v] && dist[s] + node_value[v] > 0) {
      dist[v] = dist[s] + node_value[v];
      dfs(v);
    }
  }
}

int main() {
  while(scanf("%d", &n), n != -1) {
    for(int i=0; i<103; i++) edges[i].clear();
    dist.assign(n+1, 0);
    int v, t, nt;
    for(int i=1; i<=n; i++) {
      scanf("%d%d", &v, &t);
      node_value[i] = v;
      for(int j=0; j<t; j++) {
        scanf("%d", &nt);
        edges[i].push_back(nt);
      }
    }
    dist[1] = 100;
    flag = false;
    dfs(1);
    if(flag) printf("winnable\n");
    else printf("hopeless\n");
  }
  return 0;
}
