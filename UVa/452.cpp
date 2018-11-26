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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9

// data
char line[100], pre[30];
vi edges[30];
int nodes[30];
int ans;
vi path;
vi vist;
int dist[30];

void dfs(int u) {
  vist[u] = 1;
  for(int i=0; i<(int)edges[u].size(); i++) {
    int v = edges[u][i];
    if(!vist[v]) dfs(v);
  }
  path.push_back(u);
}

int main() {
  int t;
  gets(line);
  sscanf(line, "%d", &t);
  gets(line);
  while(t--) {
    for(int i=0; i<30; i++) edges[i].clear();
    memset(nodes, 0, sizeof nodes);
    memset(dist, 0, sizeof dist);
    path.clear();
    vist.assign(30, 0);
    while(gets(line)) {
      char c;
      int val;
      if(strlen(line) == 0) break;
      sscanf(line, "%c %d%s", &c, &val, pre);
      nodes[c-'A'+1] = val;
      int len = strlen(pre);
      if(len) {
        for(int i=0; i<len; i++) {
          edges[pre[i]-'A'+1].push_back(c-'A'+1);
        }
      }else {
        edges[0].push_back(c-'A'+1);
      }
      pre[0] = '\0';
    }
    dfs(0);
    ans = 0;
    reverse(path.begin(), path.end());
    for(int i=0; i<(int)path.size(); i++) {
      for(int j=0; j<(int)edges[path[i]].size(); j++) {
        int v = edges[path[i]][j];
        dist[v] = max(dist[v], dist[path[i]] + nodes[v]);
        ans = max(ans, dist[v]);
      }
    }
    printf("%d\n", ans);
    if(t) printf("\n");
  }
  return 0;
}
