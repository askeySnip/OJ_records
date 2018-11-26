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
int m, w;
int res[125][125];
vi edges[125];
int mf, f, s, t;
vi p;

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
    p.assign(125, -1);
    bitset<125> vist; vist[s] = true;
    queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i=0; i<(int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(!vist[v] && res[u][v] > 0) {
          vist[v] = true; p[v] = u; q.push(v);
        }
      }
    }
    augment(t, inf);
    //  cout << f << endl;
    if(f == 0) break;
    mf+=f;
  }
}

int main() {
  while(scanf("%d%d", &m, &w), m || w) {
    s = 1; t = m;
    memset(res, 0, sizeof res);
    //  res[s][s+m] = inf; edges[s].push_back(s+m); edges[s+m].push_back(s);
    //  res[t][t+m] = inf; edges[t].push_back(t+m); edges[t+m].push_back(t);
    for(int i=0; i<125; i++) edges[i].clear();
    res[s][s+m] = inf; edges[s].push_back(s+m); edges[s+m].push_back(s);
    res[t][t+m] = inf; edges[t].push_back(t+m); edges[t+m].push_back(t);
    int id, c;
    for(int i=2; i<m; i++) {
      scanf("%d%d", &id, &c);
      res[id][id+m] = c;
      edges[id].push_back(id+m);
      edges[id+m].push_back(id);
    }
    int j, k, d;
    for(int i=0; i<w; i++) {
      scanf("%d%d%d", &j, &k, &d);
      res[j+m][k] = d;
      res[k+m][j] = d;
      edges[j+m].push_back(k);
      edges[k].push_back(j+m);
      edges[k+m].push_back(j);
      edges[j].push_back(k+m);  // notice: there should add four edges for 2 forward edges and 2 backward edges.
    }
    max_flow();
    printf("%d\n", mf);
  }
  return 0;
}
