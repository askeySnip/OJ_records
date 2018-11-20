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
#define maxv 38

// data
int res[maxv][maxv]; // s = 0, t = 37, 1~26 is application, 27-36 is computer
vi p;
int mf, f, s, t, u_num;

void init() {
  u_num = 0;
  memset(res, 0, sizeof res);
  for(int i=27; i<=36; i++) {
    res[i][t] = 1;
  }
}

void augment(int v, int minEdge) {
  if(v == s) {f = minEdge; return;}
  else if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f;
  }
}

void solve() {
  mf = 0;
  while(1) {
    f = 0;
    p.assign(maxv, -1);
    vi dist(maxv, 1000); dist[s] = 0; queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i=0; i<maxv; i++) {
        if(res[u][i] > 0 && dist[i] == 1000) {
          dist[i] = dist[u] + 1; q.push(i); p[i] = u;
        }
      }
    }
    augment(t, 1000);
    if(f == 0) break;
    mf += f;
  }
  if(mf != u_num) printf("!\n");
  else {
    for(int i=27; i<=36; i++) {
      bool flag = false;
      for(int j=1; j<=26; j++) {
        if(res[i][j] == 1) {
          printf("%c", j-1+'A');
          flag = true;
          break;
        }
      }
      if(!flag) printf("_");
    }
    printf("\n");
  }
}

int main() {
  char c;
  s = 0; t = 37;
  init();
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      solve();
      init();
      continue;
    }
    int appNo = c - 'A' + 1;
    c = getchar();
    int tnum = c - '0';
    u_num += tnum;
    res[s][appNo] = tnum;
    getchar();
    while((c = getchar()) != ';') {
      int compNo = c - '0'+ + 27;
      res[appNo][compNo] = 1000;
    }
    getchar();
  }
  solve();
  return 0;
}
