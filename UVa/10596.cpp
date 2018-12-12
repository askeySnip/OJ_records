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
int n, r;
int deg[205];
vi edges[205];
int vist[205];

void dfs(int u) {
  vist[u] = 1;
  for(int i=0; i<(int)edges[u].size(); i++) {
    int v = edges[u][i];
    if(!vist[v]) dfs(v);
  }
}

int main() {
  while(scanf("%d %d", &n, &r) == 2) {
    int a, b;
    memset(deg, 0, sizeof deg);
    for(int i=0; i<205; i++) edges[i].clear();
    memset(vist, 0, sizeof vist);

    for(int i=0; i<r; i++) {
      scanf("%d %d", &a, &b);
      deg[a]++; deg[b]++;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    int c = 0;
    for(int i=0; i<n; i++) {
      if(deg[i]&1) {
        c++;
      }
    }
    bool flag = true;
    dfs(a);
    for(int i=0; i<n; i++) {
      if(!vist[i] && deg[i] > 0) {
        flag = false;
        break;
      }
    }

    if(r > 0 && c == 0 && flag) printf("Possible\n");
    else printf("Not Possible\n");
  }
  return 0;
}
