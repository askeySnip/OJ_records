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
int n, r, q;
int busyness[202];
vii edges[202];
vi dist;

int inline xxx(int x) {
  return x*x*x;
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1) {
    for(int i=1; i<=n; i++) scanf("%d", &busyness[i]);
    for(int i=0; i<202; i++) edges[i].clear();
    dist.assign(n+1, inf);
    scanf("%d", &r);
    int x, y;
    for(int i=0; i<r; i++) {
      scanf("%d %d", &x, &y);
      edges[x].push_back(ii(y, xxx(busyness[y] - busyness[x])));
    }
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
      for(int u=1; u<=n; u++) {
        for(int j=0; j<(int)edges[u].size(); j++) {
          ii v = edges[u][j];
          dist[v.first] = min(dist[v.first], dist[u] + v.second);
        }
      }
    }
    vi dist2 = dist;
    for(int i=0; i<n-1; i++) {
      for(int u=1; u<=n; u++) {
        for(int j=0; j<(int)edges[u].size(); j++) {
          ii v = edges[u][j];
          dist2[v.first] = min(dist2[v.first], dist2[u] + v.second);
        }
      }
    }
    for(int i=1; i<=n; i++) {
      if(dist2[i] < dist[i]) dist[i] = -1;
    }
    printf("Set #%d\n", ++kase);
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
      scanf("%d", &y);
      if(dist[y] < 3 || dist[y] > inf/2) printf("?\n");
      else printf("%d\n", dist[y]);
    }
  }
  return 0;
}
