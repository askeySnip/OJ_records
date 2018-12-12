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
char name[100];
int r, c;
int graph[10024];
int vist[10024];
vi path;
vi dist;

void dfs(int u) {
  vist[u] = 1;
  if(u%c && !vist[u-1] && graph[u] > graph[u-1]) dfs(u-1);
  if((u+1)%c && !vist[u+1] && graph[u] > graph[u+1]) dfs(u+1);
  if(u/c && !vist[u-c] && graph[u] > graph[u-c]) dfs(u-c);
  if(c*r-u > c && !vist[u+c] && graph[u] > graph[u+c]) dfs(u+c);
  path.push_back(u);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(vist, 0, sizeof vist);
    path.clear();
    scanf("%s %d %d", name, &r, &c);
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        scanf("%d", &graph[i*c+j]);
      }
    }
    for(int i=0; i<r*c; i++) {
      if(!vist[i]) dfs(i);
    }
    reverse(path.begin(), path.end());
    dist.assign(r*c, 1);
    int ans = 1;
    for(int i=0; i<(int)path.size(); i++) {
      int u = path[i];
      if(u%c  && graph[u] > graph[u-1]) dist[u-1] = max(dist[u-1], dist[u]+1), ans = max(ans, dist[u-1]);
      if((u+1)%c  && graph[u] > graph[u+1]) dist[u+1] = max(dist[u+1], dist[u]+1), ans = max(ans, dist[u+1]);
      if(u/c && graph[u] > graph[u-c]) dist[u-c] = max(dist[u-c], dist[u]+1), ans = max(ans, dist[u-c]);
      if(c*r-u > c && graph[u] > graph[u+c]) dist[u+c] = max(dist[u+c], dist[u]+1), ans = max(ans, dist[u+c]);
    }

    printf("%s: %d\n", name, ans);
  }
  return 0;
}
