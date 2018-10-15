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
#define UNVISITED -1
int n, dfs_count, dfs_root, dfs_child;
vector<vi> graph;
vi dfs_num, dfs_low, dfs_parent;
vii bridge;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfs_count++;
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      if(u == dfs_root) dfs_child++;

      dfs(v);

      if(dfs_low[v] > dfs_num[u]) {
        if(v > u) bridge.push_back(ii(u, v));
        else bridge.push_back(ii(v, u));
      }

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }else if(dfs_parent[u] != v) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}
int main() {
  int f, t, num;

  while(scanf("%d", &n) == 1) {

    graph.assign(n, vector<int>());
    bridge.clear();
    for(int i=0; i<n; i++) {
      scanf("%d (%d)", &f, &num);
      for(int j=0; j<num; j++) {
        scanf("%d", &t);
        graph[f].push_back(t);
        graph[t].push_back(f);
      }
    }

    // inital data
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0);
    dfs_count = 0;
    
    for(int i=0; i<n; i++) {
      if(dfs_num[i] == UNVISITED){
        dfs_root = i;
        dfs_child = 0;
        dfs(i);
      }
    }
    sort(bridge.begin(), bridge.end());
    printf("%d critical links\n", (int)bridge.size());
    for(int i=0; i<(int)bridge.size(); i++) {
      printf("%d - %d\n", bridge[i].first, bridge[i].second);
    }
    printf("\n");
  }
}
