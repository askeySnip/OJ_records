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
#define maxn 2024
#define UNVISITED -1
int n, m, dfs_count;
vi graph[maxn];
vi dfs_num, dfs_low, visted, s;
int ans;
void tarjan(int u) {
  dfs_num[u] = dfs_low[u] = dfs_count++;
  visted[u] = 1;
  s.push_back(u);
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == UNVISITED) tarjan(v);
    if(visted[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_num[u] == dfs_low[u]) {
    while(1) {
      int v = s.back();
      s.pop_back();
      visted[v] = 0;
      if(v == u) break;
    }
    ans++;
    //  cout << u << endl;
  }
}
int main() {
  int f, t, p;
  while(scanf("%d %d", &n, &m), n||m) {
    for(int i=0; i<maxn; i++) graph[i].clear();
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &f, &t, &p);
      graph[f].push_back(t);
      if(p == 2) graph[t].push_back(f);
    }
    //  s.clear();
    ans = 0;
    dfs_count = 0;
    dfs_num.assign(n+2, UNVISITED);
    dfs_low.assign(n+2, 0);
    visted.assign(n+2, 0);

    for(int i=1; i<=n; i++) {
      if(dfs_num[i] == UNVISITED) tarjan(i);
    }
    printf("%d\n", ans==1);
  }
  return 0;
}
