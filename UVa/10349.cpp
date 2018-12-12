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
int h, w;
char graph[43][13];
vi edges[403];
int n_nodes;
vi match, vis;

int Aug(int l) {
  if(vis[l]) return 0;
  vis[l] = 1;
  for(int j=0; j<(int)edges[l].size(); j++) {
    int r = edges[l][j];
    if(match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    n_nodes = 0;
    for(int i=0; i<403; i++) edges[i].clear();
    scanf("%d %d", &h, &w);
    for(int i=0; i<h; i++) {
      scanf("%s", graph[i]);
    }
    int grid[43][13];
    vi left;
    memset(grid, 0, sizeof grid);
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        if(graph[i][j] == '*') {
          grid[i][j] = n_nodes++;
          left.push_back((i+j)%2);
          if(i > 0 && graph[i-1][j] == '*') {
            edges[grid[i][j]].push_back(grid[i-1][j]);
            edges[grid[i-1][j]].push_back(grid[i][j]);
          }
          if(j > 0 && graph[i][j-1] == '*') {
            edges[grid[i][j]].push_back(grid[i][j-1]);
            edges[grid[i][j-1]].push_back(grid[i][j]);
          }
        }
      }
    }
    int MCBM = 0;
    match.assign(n_nodes, -1);
    for(int i=0; i<n_nodes; i++) {
      if(left[i] == 0) continue;
      vis.assign(n_nodes, 0);
      MCBM += Aug(i);
    }
    printf("%d\n", n_nodes - MCBM);
  }
  return 0;
}
