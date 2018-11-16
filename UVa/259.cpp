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
#define inf 1e6

// node 0 reprezation the start node 37 for the end node
// [1~10] is the computer
// [11~36] is the application

// data
int res[40][40];
vi edges[40];
int u_num = 0;
int f, mf;
vi p;

void init() {
  for(int i=0; i<40; i++) edges[i].clear();
  u_num = 0;
  memset(res, 0, sizeof res);
  for(int i=1; i<=10; i++) {
    res[i][37] = 1;
    edges[i].push_back(37);
  }
  p.assign(40, -1);
}

void augment(int v, int minEdge) {
  if(v == 0) {
    f = minEdge;
    return;
  }else if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f;
  }
}

void solve() {
  mf = 0;
  while(1) {
    f = 0;
    bitset<40> vist; vist[0] = true;
    queue<int> q; q.push(0);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == 37) break;
      for(int i = 0; i<(int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(res[u][v] > 0 && !vist[v]) {
          vist[v] = true;
          q.push(v);
          p[v] = u;
        }
      }
    }
    augment(37, inf);
    if(f == 0) break;
    mf += f;
  }
  if(mf < u_num) printf("!\n");
  else {
    for(int i=1; i<=10; i++) {
      if(p[i] == -1) printf("_");
      else printf("%c", p[i]-11+'A');
    }
  }
}

int main() {
  char c;
  init();
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      solve();
      init();
    }
    int app_node = c - 'A' + 11;
    c = getchar();
    int t = c - '0';
    u_num += t;
    res[0][app_node] = t;
    edges[0].push_back(app_node);
    getchar();
    while((c = getchar()) != ';') {
      t = c - '0';
      res[app_node][t+1] = inf;
      edges[app_node].push_back(t+1);
    }
    getchar();
  }
  return 0;
}
