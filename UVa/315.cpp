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
int n, ans, dfs_root, root_children, dfs_count;
vi graph[103];
vi dfs_num;
vi dfs_low;
vi parent;
vi articulation_vertex;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfs_count++;
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == UNVISITED){
      parent[v] = u;
      if(u == dfs_root) root_children++;
      
      dfs(v);
      //  cout << v << " " << u << dfs_low[v] << " " << dfs_num[u] << endl;
      if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
      
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if(v != parent[u]){
      dfs_low[u] = min(dfs_num[v], dfs_low[u]);
    }
  }
}
int main() {
  while(scanf("%d", &n), n) {
    for(int i=0; i<103; i++) graph[i].clear();
    int t, f; char c;
    while(scanf("%d", &t) == 1 && t) {
      while(scanf("%d%c", &f, &c) == 2){
        graph[t].push_back(f);
        graph[f].push_back(t);
        if(c == '\n') break;
      }
    }
    dfs_count = 0;
    articulation_vertex.assign(n+3, 0);
    dfs_num.assign(n+3, UNVISITED);
    dfs_low.assign(n+3, 0);
    parent.assign(n+3, 0);
    ans = 0;
    for(int i=1; i<=n; i++) {
      if(dfs_num[i] == UNVISITED) {
        dfs_root = i;
        root_children = 0;
        dfs(i);
        articulation_vertex[i] = (root_children > 1);
      }
    }
    for(int i=1; i<=n; i++) {
      if(articulation_vertex[i]) {

        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
