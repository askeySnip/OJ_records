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
int n, m;
vii edges[1024];
vi dis;

int main() {
  int c;
  scanf("%d", &c);
  while(c--) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<1024; i++) edges[i].clear();
    dis.assign(n, inf);
    int x, y, t;
    for(int i=0; i<m; i++) {
      scanf("%d %d %d", &x, &y, &t);
      edges[x].push_back(ii(y, t));
    }
    dis[0] = 0;
    for(int i=0; i<n-1; i++) {
      for(int u=0; u<n; u++) {
        for(int j=0; j<(int)edges[u].size(); j++) {
          ii v = edges[u][j];
          dis[v.first] = min(dis[v.first], dis[u] + v.second);
        }
      }
    }
    bool ans = false;
    for(int u=0; u<n; u++) {
      for(int j=0; j<(int)edges[u].size(); j++) {
        ii v = edges[u][j];
        if(dis[v.first] > dis[u] + v.second) {
          ans = true;
          break;
        }
      }
    }
    if(ans) printf("possible\n");
    else printf("not possible\n");
  }
  return 0;
}
