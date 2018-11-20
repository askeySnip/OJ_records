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
int n, s, t, c;
int rec[103][103];
int fm, f;
vi p;

void augment(int v, int minEdge) {
  if(v == s) {f = minEdge; return;}
  else if(p[v] != -1) {
    augment(p[v], min(minEdge, rec[p[v]][v]));
    rec[p[v]][v] -= f; rec[v][p[v]] += f;
  }
}

void solve() {
  fm = 0;
  while(1) {
    f = 0;
    bitset<103> vist; vist[s] = true;
    p.assign(103, -1);
    queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int v=1; v<=n; v++) {
        if(rec[u][v] > 0 && !vist[v]) {
          q.push(v); vist[v] = true; p[v] = u;
        }
      }
    }
    augment(t, inf);
    if(f == 0) break;
    fm += f;
  }
}

int main() {
  int kase = 0;
  while(scanf("%d", &n), n) {
    memset(rec, 0, sizeof rec);

    scanf("%d%d%d", &s, &t, &c);
    int a, b, v;
    for(int i=0; i<c; i++) {
      scanf("%d%d%d", &a, &b, &v);
      rec[a][b] += v;
      rec[b][a] += v;
    }
    solve();
    printf("Network %d\n", ++kase);
    printf("The bandwidth is %d.\n\n", fm);
  }
  return 0;
}
