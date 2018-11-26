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
int n;
vi edges[1000];
vi path;
int vist[1000];

void dfs(int u) {
  vist[u] = 1;
  for(int i=0; i<(int)edges[u].size(); i++) {
    int v = edges[u][i];
    if(!vist[v]) dfs(v);
  }
  path.push_back(u);
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1) {
    if(kase++) printf("\n");
    for(int i=0; i<1000; i++) edges[i].clear();
    path.clear();
    memset(vist, 0, sizeof vist);
    int m, t;
    for(int i=0; i<n; i++) {
      scanf("%d", &m);
      for(int j=0; j<m; j++) {
        scanf("%d", &t);
        edges[i].push_back(t);
      }
      if(m == 0) edges[i].push_back(n);
    }
    dfs(0);
    reverse(path.begin(), path.end());
    vi dist(n+1, 0);
    dist[0] = 1;
    for(int i=0; i<(int)path.size(); i++) {
      int u = path[i];
      for(int j=0; j<(int)edges[u].size(); j++) {
        dist[edges[u][j]] += dist[u];
      }
    }
    printf("%d\n", dist[n]);
  }
  return 0;
}
