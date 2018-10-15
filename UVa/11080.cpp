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
int v, e;
vi graph[203];
vi color;
int c[3];
bool flag;
void bfs(int u) {
  queue<ii> q;
  q.push(ii(u, 1));
  color[u] = 1;
  c[1]++;
  while(!q.empty()) {
    if(!flag) break;
    ii p = q.front();
    q.pop();
    for(int i=0; i<(int)graph[p.first].size(); i++) {
      if(color[graph[p.first][i]] == 0) {
        q.push(ii(graph[p.first][i], 3-p.second));
        color[graph[p.first][i]] = 3-p.second;
        c[3-p.second]++;
      }else if(color[graph[p.first][i]] == color[p.first]) {
        flag = false;
        break;
      }
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &v, &e);
    for(int i=0; i<203; i++) graph[i].clear();
    int f, t;
    for(int i=0; i<e; i++) {
      scanf("%d %d", &f, &t);
      graph[f].push_back(t);
      graph[t].push_back(f);
    }
    color.assign(v, 0);
    flag = true;
    int ans = 0;
    for(int i=0; i<v; i++) {
      if(color[i]) continue;
      c[1] = c[2] = 0;
      bfs(i);
      if(!flag) break;
      // notice the only one node case; 
      if(c[1] == 0) c[1] = 1;
      if(c[2] == 0) c[2] = 1;
      ans += min(c[1], c[2]);
    }
    if(flag) printf("%d\n", ans);
    else printf("-1\n");
  }
  return 0;
}
