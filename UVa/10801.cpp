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


// data
int n, k;
int t[5];
vi f[5];
int vist[512];
vii edges[512];
vi flor[100];

int main() {
  while(scanf("%d%d", &n, &k) == 2) {
    for(int i=0; i<n; i++) scanf("%d", &t[i]);
    memset(vist, -1, sizeof vist);
    for(int i=0; i<512; i++) edges[i].clear();
    for(int i=0; i<5; i++) f[i].clear();
    for(int i=0; i<100; i++) flor[i].clear();
    char c; int fl;
    for(int i=0; i<n; i++) {
      while(scanf("%d%c", &fl, &c)){
        f[i].push_back(fl);
        flor[fl].push_back(i);
        if(c == '\n') break;
      }
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<(int)f[i].size()-1; j++) {
        edges[i*100+f[i][j]].push_back(ii(f[i][j+1]+i*100, t[i] * (f[i][j+1] - f[i][j])));
      }
      for(int j=1; j<(int)f[i].size(); j++) {
        edges[i*100+f[i][j]].push_back(ii(f[i][j-1]+i*100, t[i] * (f[i][j] - f[i][j-1])));
      }
    }
    for(int i=0; i<100; i++) {
      if(flor[i].size() < 2) continue;
      for(int j=0; j<(int)flor[i].size(); j++) {
        for(int k=j+1; k<(int)flor[i].size(); k++) {
          edges[flor[i][j] * 100 + i].push_back(ii(flor[i][k]*100+i, 60));
          edges[flor[i][k]*100 + i].push_back(ii(flor[i][j]*100+i, 60));
        }
      }
    }
    priority_queue<ii, vii, greater<ii> > pq;
    for(int i=0; i<(int)flor[0].size(); i++) {
      pq.push(ii(0, flor[0][i] * 100));
    }
    while(!pq.empty()) {
      ii p = pq.top(); pq.pop();
      if(vist[p.second] != -1) continue;
      vist[p.second] = p.first;
      if(p.second%100 == k) break;
      for(int i=0; i<(int)edges[p.second].size(); i++) {
        int u = edges[p.second][i].first;
        if(vist[u] == -1) pq.push(ii(p.first + edges[p.second][i].second, u));
      }
    }
    int ans = -1;
    for(int i=0; i<n; i++) {
      if(vist[i*100+k] != -1){
        ans = vist[i*100+k]; break;
      }
    }
    if(ans != -1) printf("%d\n", ans);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
