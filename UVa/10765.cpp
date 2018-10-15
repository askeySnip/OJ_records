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
int n, m, dfs_count, dfs_root, root_child;
vi graph[10024];
vi dfs_num, dfs_low, dfs_parent, val;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfs_count++;
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      if(u == dfs_root) root_child++;

      dfs(v);

      if(dfs_low[v] >= dfs_num[u]) val[u]++;

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }else if(v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
  while(scanf("%d %d", &n, &m), n || m) {
    int a, b;
    for(int i=0; i<10024; i++) graph[i].clear();
    while(scanf("%d %d", &a, &b), a>-1 && b>-1) {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0);
    val.assign(n, 1);
    dfs_count = 0;
    // for(int i=0; i<n; i++) {
    //   if(dfs_num[i] == UNVISITED) {
    //     dfs_root = i;
    //     root_child = 0;
    //     dfs(i);
    //     if(root_child == 1) val[i] = 1;
    //   }
    // }
    dfs_root = 0;
    root_child = 0;
    dfs(0);
    if(root_child == 1) val[0] = 1;
    else val[0]--;              // ******this is the key, draw the graph and you must know that the val[root] must set to zero.
    vii ans;
    for(int i=0; i<n; i++) ans.push_back(ii(-val[i], i));
    sort(ans.begin(), ans.end());
    for(int i=0; i<m; i++) {
      printf("%d %d\n", ans[i].second, -ans[i].first);
    }
    printf("\n");
  }
  return 0;
}
