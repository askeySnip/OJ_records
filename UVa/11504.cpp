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

vi graph[100003];
int n, m;
vi dfs_num, dfs_low, visted, stk, dfs_parent;
int dfs_counts, dfs_root;
set<int> s;
void tarjan(int u) {
  dfs_num[u] = dfs_low[u] = dfs_counts++;
  stk.push_back(u);
  visted[u] = 1;
  for(int i=0; i<(int)graph[u].size(); i++) {
    int v = graph[u][i];
    if(dfs_num[v] == -1) tarjan(v);
    if(visted[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if(dfs_low[u] == dfs_num[u]) {
    
    while(1){
      int v = stk.back(); stk.pop_back();
      dfs_low[v] = dfs_num[u];
      // cout << v << " ";
      visted[v] = 0;
      if(v == u) break;
    }
    //cout << endl;
    s.insert(dfs_low[u]);
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    dfs_num.assign(n+2, -1);
    dfs_low.assign(n+2, 0);
    visted.assign(n+2, 0);
    dfs_parent.assign(n+2, 0);
    dfs_counts = 0;
    s.clear();
    for(int i=0; i<100003; i++) graph[i].clear();
    int x, y;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &x, &y);
      graph[x].push_back(y);
    }
    //  cout << endl;
    for(int i=1; i<=n; i++) {
      if(dfs_num[i] == -1) tarjan(i);
    }
    //  cout << "dfs_low dfs_num" << endl;
    //  for(int i=1; i<=n; i++) cout << dfs_low[i] <<  " " << dfs_num[i] << " " << endl;;
    //  cout << endl;
    //  for(auto it = s.begin(); it!= s.end(); it++) cout << *it << endl;
    //  cout << s.size() << endl;
    for(int i=1; i<=n; i++) {
      for(int j=0; j<(int)graph[i].size(); j++) {
        int v = graph[i][j];
        if(dfs_low[v] != dfs_low[i] && s.find(dfs_low[v]) != s.end()) {
          //  cout << v << " " << i << endl;
          s.erase(dfs_low[v]);
        }
      }
    }
    printf("%d\n", (int)s.size());
  }
  return 0;
}
