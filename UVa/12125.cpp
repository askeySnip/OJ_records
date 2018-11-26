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
int n;
double d;
int res[256][256], tres[256][256];
int mf, f, s, t;
vector<pair<ii, ii> > flos;
vi edges[256];
vi p;

inline double dist(ii& a, ii& b) {
  return sqrt( (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) );
}

void augment(int v, int minEdge) {
  if(v == s) {f = minEdge; return;}
  else if(p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f;
  }
}

void max_flow() {
  mf = 0;
  while(1) {
    f = 0;
    p.assign(256, -1);
    bitset<256> vist; vist[s] = true;
    queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i=0; i<(int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(res[u][v] > 0 && !vist[v]) {
          p[v] = u; q.push(v); vist[v] = true;
        }
      }
    }
    augment(t, inf);
    if(f == 0) break;
    mf += f;
  }
}

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    int tot_num = 0;
    memset(res, 0, sizeof res);
    flos.clear();
    scanf("%d %lf", &n, &d);
    s = 0; t = n*2+1;
    int x, y, np, mj;
    for(int i=0; i<n; i++) {
      scanf("%d%d%d%d", &x, &y, &np, &mj);
      flos.push_back(make_pair(ii(x, y), ii(np, mj)));
      tot_num += np;
      if(np > 0) {
        res[s][i+1] = np;
        edges[s].push_back(i+1);
        edges[i+1].push_back(s);
      }
      res[i+1][i+1+n] = mj;
      edges[i+1].push_back(i+1+n);
      edges[i+1+n].push_back(i+1);
    }
    for(int i=0; i<(int)flos.size(); i++) {
      for(int j=i+1; j<(int)flos.size(); j++) {
        if(dist(flos[i].first, flos[j].first) <= d) {
          res[i+1+n][j+1] = inf;
          res[j+1+n][i+1] = inf;
          edges[i+1+n].push_back(j+1);
          edges[j+1].push_back(i+1+n);
          edges[j+1+n].push_back(i+1);
          edges[i+1].push_back(j+1+n);
        }
      }
    }

    vi ans;
    memcpy(tres, res, sizeof tres);
    for(int i=0; i<(int)flos.size(); i++) {
      res[i+1][t] = inf;
      edges[i+1].push_back(t);
      edges[t].push_back(i+1);
      max_flow();
      if(mf == tot_num) {
        ans.push_back(i);
      }
      memcpy(res, tres, sizeof res);
    }
    if(ans.empty()) printf("-1\n");
    else {
      for(int i=0; i<(int)ans.size(); i++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
