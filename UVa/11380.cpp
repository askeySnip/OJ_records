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
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// data
int x, y, p;
char area[52][52];
int res[2000][2000];
int mf, f, s, t;
vi parent;
vi edges[2000];

void augment(int v, int minEdge) {
  if(v == s) {f = minEdge; return;}
  else if(parent[v] != -1) {
    augment(parent[v], min(minEdge, res[parent[v]][v]));
    res[parent[v]][v] -= f; res[v][parent[v]] += f;
  }
}

void solve() {
  mf = 0;
  while(1) {
    f = 0;
    parent.assign(2000, -1);
    bitset<2000> vist; vist[s] = true;
    queue<int> q; q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i=0; i<(int)edges[u].size(); i++) {
        int v = edges[u][i];
        if(res[u][v] > 0 && !vist[v]) {
          vist[v] = true; parent[v] = u; q.push(v);
        }
      }
    }
    augment(t, inf);
    if(f == 0) break;
    mf += f;
  }
}

int main() {
  while(scanf("%d%d%d", &x, &y, &p) == 3) {
    memset(res, 0, sizeof res);
    for(int i=0; i<2000; i++) edges[i].clear();
    s = 0;
    t = 2 * x * y + 1;
    for(int i=0; i<x; i++) {
      scanf("%s", area[i]);
    }
    for(int i=0; i<x; i++) {
      for(int j=0; j<y; j++) {
        int pos1 = i * y + j + 1;
        int pos2 = pos1 + x * y;
        if(area[i][j] == '*' || area[i][j] == '.') {
          if(area[i][j] == '*') {
            res[0][pos1] = 1;
            edges[0].push_back(pos1);
            edges[pos1].push_back(0);
          }
          res[pos1][pos2] = 1;
          edges[pos1].push_back(pos2);
          edges[pos2].push_back(pos1);
          for(int k=0; k<4; k++) {
            int tx = i + dx[k], ty = j+dy[k];
            if(tx >=0 && tx < x && ty>=0 && ty < y) {
              if(area[tx][ty] == '*' || area[tx][ty] == '.' || area[tx][ty] == '@' || area[tx][ty] == '#') {
                res[pos2][tx*y+ty+1] = inf;
                edges[pos2].push_back(tx*y+ty+1);
                edges[tx*y+ty+1].push_back(pos2);
              }
            }
          }
        }else if(area[i][j] == '@' || area[i][j] == '#') {
          if(area[i][j] == '#') {
            res[pos2][t] = p;
            edges[pos2].push_back(t);
            edges[t].push_back(pos2);
          }
          res[pos1][pos2] = inf;
          edges[pos1].push_back(pos2);
          edges[pos2].push_back(pos1);
          for(int k=0; k<4; k++) {
            int tx = i + dx[k], ty = j + dy[k];
            if(tx >= 0 && tx < x && ty>=0 && ty < y) {
              if(area[tx][ty] == '*' || area[tx][ty] == '.' || area[tx][ty] == '@' || area[tx][ty] == '#') {
                res[pos2][tx*y+ty+1] = inf;
                edges[pos2].push_back(tx*y+ty+1);
                edges[tx*y+ty+1].push_back(pos2);
              }
            }
          }
        }
      }
    }
    solve();

    printf("%d\n", mf);
  }
  return 0;
}
