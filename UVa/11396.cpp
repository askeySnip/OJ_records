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
int v;
vi graph[303];
int vc = 0; // nodes in a connect graph
bool flag;
vi color;

void bfs(int u) {
  color[u] = 1;
  queue<ii> q;
  q.push(ii(u, 1));
  vc++;
  while(!q.empty()) {
    ii p = q.front();
    q.pop();
    vi& tv = graph[p.first];
    for(int i=0; i<(int)tv.size(); i++) {
      if(color[tv[i]] == 0) {
        color[tv[i]] = 3 - p.second;
        q.push(ii(tv[i], 3-p.second));
        vc++;
      }else if(color[tv[i]] == p.second) {
        flag = false;
        break;
      }
    }
    if(!flag) break;
  }
}
int main() {
  int a, b;
  while(scanf("%d", &v), v) {
    for(int i=0; i<303; i++) graph[i].clear();
    while(scanf("%d %d", &a, &b), a&&b) {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    color.assign(v+1, 0);
    if(v< 4 || v%2) printf("NO\n");
    else {
      vc = 0;
      flag = true;
      for(int i=1; i<=v; i++) {
        if(!flag) break;
        if(color[i] == 0) bfs(i);
        if(vc < 4 || vc%2) flag = false;
      }
      if(flag) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}
