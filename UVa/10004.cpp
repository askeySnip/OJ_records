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
int main() {
  int n, l, f, t;
  int graph[203][203];
  int color[203];
  while(scanf("%d", &n), n) {
    scanf("%d", &l);
    memset(graph, 0, sizeof graph);
    memset(color, 0, sizeof color);
    for(int i=0; i<l; i++) {
      scanf("%d %d", &f, &t);
      graph[f][t] = graph[t][f] = 1;
    }
    bool flag = true;
    for(int i=0; i<n; i++) {
      if(!flag) break;
      if(color[i]) continue;
      queue<ii> q;
      q.push(ii(i, 1));
      color[i] = 1;
      while(!q.empty()) {
        if(!flag) break;
        ii p = q.front();
        q.pop();
        for(int j=0; j<n; j++) {
          if(graph[p.first][j]) {
            if(color[j] == p.second) flag = false;
            else if(color[j] == 0) {
              q.push(ii(j, 3-p.second));
              color[j] = 3-p.second;
            }
          }
        }
      }
    }
    if(flag) printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");
  }
  return 0;
}
