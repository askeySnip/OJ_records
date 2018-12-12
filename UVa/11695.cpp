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
int n;
vi edges[2503];
vi path;
int delf, delt;

void bfs(int s) {
  path.clear();
  queue<ii> q;
  q.push(ii(s, 0));
  bitset<2503> vist;
  vi p(n+1, -1);
  vist[s] = true;
  ii it;
  while(!q.empty()) {
    it = q.front(); q.pop();
    for(int i=0; i<(int)edges[it.first].size(); i++) {
      int v = edges[it.first][i];
      if((delf==it.first && delt==v) || (delf==v && delt==it.first)) continue;
      if(!vist[v]) {
        q.push(ii(v, it.second)); vist[v] = true; p[v] = it.first;
      }
    }
  }
  int i = it.first;
  while(i != -1) {
    path.push_back(i);
    i = p[i];
  }
}

void solve() {
  vi path2 = path;
  int ans = inf, df, dt, addf, addt;
  for(int i=0; i<(int)path2.size()-1; i++) {
    delf = path2[i], delt = path2[i+1];
    bfs(path2[i]);
    bfs(path[0]);
    int lenA = path.size();
    vi pathA = path;
    bfs(path2[i+1]);
    bfs(path[0]);
    int lenB = path.size();
    vi pathB = path;
    int tlen = max(max(lenA-1, lenB-1), lenA/2+lenB/2+1);
    if(ans > tlen) {
      ans = tlen;
      //cout << ans << " " << lenA << " " << lenB << endl;
      df = delf, dt = delt, addf = pathA[lenA/2], addt = pathB[lenB/2];
      // for(int i=0; i<lenA; i++) cout << pathA[i] << " ";
      // cout << endl;
      // for(int i=0; i<lenB; i++) cout << pathB[i] << " ";
      // cout << endl;
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", df, dt);
  printf("%d %d\n", addf, addt);
}

int main() {
  int t, a, b;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) edges[i].clear();
    for(int i=0; i<n-1; i++) {
      scanf("%d %d", &a, &b);
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    bfs(1);
    //cout << path[0] << endl;
    bfs(path[0]);
    //cout << path.back() << endl;
    solve();
  }
  return 0;
}
