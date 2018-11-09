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
int e, n, t;
vi edges[2503];
int vist[2503];
int counts[2503];

void solve(int s) {
  queue<ii> q;
  memset(vist, 0, sizeof vist);
  memset(counts, 0, sizeof counts);
  int ans = 0, ansid = -1;
  q.push(ii(s, 0));
  while(!q.empty()) {
    ii p = q.front(); q.pop();
    if(vist[p.first]) continue;
    vist[p.first] = 1;
    counts[p.second]++;
    for(int i=0; i<(int)edges[p.first].size(); i++) {
      int v = edges[p.first][i];
      if(vist[v]) continue;
      q.push(ii(v, p.second+1));
    }
  }
  for(int i=1; i<2503; i++) {
    if(counts[i] > ans) {
      ans = counts[i];
      ansid = i;
    }
  }
  if(ans) printf("%d %d\n", ans, ansid);
  else printf("0\n");
}
int main() {
  scanf("%d", &e);
  for(int i=0; i<e; i++) {
    scanf("%d", &n);
    for(int j=0; j<n; j++) {
      scanf("%d", &t);
      edges[i].push_back(t);
    }
  }
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    int s;
    scanf("%d", &s);
    solve(s);
  }
  return 0;
}
