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
vi edges[5003];
int farest, len;
vii path;

void bfs(int i) {
  bitset<5003> vist;
  path.clear();
  queue<ii> q;
  q.push(ii(i, 0));
  while(!q.empty()) {
    ii p = q.front(); q.pop();
    if(vist[p.first]) continue;
    vist[p.first] = 1;
    path.push_back(p);
    for(int j=0; j<(int)edges[p.first].size(); j++) {
      int v = edges[p.first][j];
      if(!vist[v]) q.push(ii(v, p.second+1));
    }
    farest = p.first, len = p.second;
  }
}

int main() {
  while(scanf("%d", &n) == 1) {

    for(int i=1; i<=n; i++) edges[i].clear();
    path.clear();

    int tn;
    for(int i=1; i<=n; i++) {
      scanf("%d", &tn);
      int t;
      for(int j=0; j<tn; j++) {
        scanf("%d", &t);
        edges[i].push_back(t);
      }
    }

    bfs(1);
    int a = farest;
    bfs(a);
    vii path2 = path;
    bfs(farest);
    bitset<5003> bestroot, worstroot;
    if(len%2) {
      for(int i=0; i<(int)path.size(); i++) {
        if(path[i].second == len/2 || path[i].second == len/2+1) bestroot[path[i].first] = 1;
        if(path[i].second == len) worstroot[path[i].first] = 1;
      }
      for(int i=0; i<(int)path2.size(); i++) {
        if(path2[i].second != len/2 && path2[i].second != len/2+1) bestroot[path2[i].first] = 0;   // notice there should be && not || which makes me the first commit WA
        if(path2[i].second == len) worstroot[path2[i].first] = 1;
      }
    }else {
      for(int i=0; i<(int)path.size(); i++) {
        if(path[i].second == len/2) bestroot[path[i].first] = 1;
        if(path[i].second == len) worstroot[path[i].first] = 1;
      }
      for(int i=0; i<(int)path2.size(); i++) {
        if(path2[i].second != len/2) bestroot[path2[i].first] = 0;
        if(path2[i].second == len) worstroot[path2[i].first] = 1;
      }
    }
    printf("Best Roots  :");
    for(int i=1; i<=n; i++) {
      if(bestroot[i]) printf(" %d", i);
    }
    printf("\n");
    printf("Worst Roots :");
    for(int i=1; i<=n; i++) {
      if(worstroot[i]) printf(" %d", i);
    }
    printf("\n");
  }
  return 0;
}
