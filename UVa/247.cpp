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
int n, m;
char name[100];
map<string, int> mp;
vi graph[30];
vi dfs_num, dfs_low, visted, s;
int dfs_counts;
vector<string> names;

void tarjan(int u) {
  dfs_num[u] = dfs_low[u] = dfs_counts++;
  s.push_back(u);
  visted[u] = 1;
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == UNVISITED) tarjan(v);
    if(visted[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_low[u] == dfs_num[u]) {
    int i = 0;
    while(1) {
      if(i) printf(", ");
      i++;
      int v = s.back(); s.pop_back();
      visted[v] = 0;
      printf("%s", names[v].c_str());
      if(v == u) break;
    }
    printf("\n");
  }
}
int main() {
  int kase = 0;
  while(scanf("%d %d", &n, &m), n||m) {
    // initaliza 
    for(int i=0; i<30; i++) graph[i].clear();
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    visted.assign(n, 0);
    dfs_counts = 0;
    mp.clear();
    names.clear();
    s.clear();
    int id = 0;
    for(int i=0; i<m; i++) {
      scanf("%s", name);
      if(mp.find(name) == mp.end()) {
        names.push_back(name);
        mp[name] = id++;
      }
      int f = mp[name];
      scanf("%s", name);
      if(mp.find(name) == mp.end()) {
        names.push_back(name);
        mp[name] = id++;
      }
      graph[f].push_back(mp[name]);
    }
    printf("Calling circles for data set %d:\n", ++kase);
    for(int i=0; i<n; i++) {
      if(dfs_num[i] == UNVISITED) {
        tarjan(i);
      }
    }
  }
  return 0;
}
