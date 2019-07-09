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
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
vii edges[5024];
int dist[5024];
int dist2[5024];

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  int a, b, c;
  REP(i, 0, r) {
    scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    edges[a].push_back(ii(b, c));
    edges[b].push_back(ii(a, c));
  }
  fill(dist, dist+n, inf);
  fill(dist2, dist2+n, inf);
  dist[0] = 0;
  priority_queue<ii, vii, greater<ii> > pq;
  pq.push(ii(0, 0));
  while(!pq.empty()) {
    ii p = pq.top(); pq.pop();
    if(dist2[p.first] < p.second) continue;
    REP(i, 0, edges[p.first].size()) {
      ii v = edges[p.first][i];
      int d = v.second + p.second;
      if(dist[v.first] > d) {
        swap(dist[v.first], d);
        pq.push(ii(v.first, dist[v.first]));
      }
      if(dist2[v.first] > d && dist[v.first] < d) {
        dist2[v.first] = d;
        pq.push(ii(v.first, dist2[v.first]));
      }
    }
  }
  printf("%d\n", dist2[n-1]);
  return 0;
}
