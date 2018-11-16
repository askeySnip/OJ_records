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
typedef pair<double, double> ii;
typedef vector<pair<double, double> > vii;

// struct
const double inf = 1e16;

// data
int n;
vii nodes, tnodes;

double dist(ii& a, ii&b) {
  return sqrt( (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) );
}

double divide_solve(int l, int r) {
  if(l == r) return inf;
  int mid = (l + r) / 2;
  int sz = 0;
  double d = min(divide_solve(l, mid), divide_solve(mid+1, r));
  for(int i=l, j=mid+1; i<=mid; i++) {
    while(j<=r && nodes[j].second <= nodes[i].second) tnodes[sz++] = nodes[j++];
    tnodes[sz++] = nodes[i];
  }

  for(int i=0; i<sz; i++) nodes[i+l] = tnodes[i];
  sz = 0;
  for(int i=l; i<=r; i++) {
    if(fabs(nodes[i].first-nodes[mid].first) < d) tnodes[sz++] = nodes[i];
  }

  for(int i=0; i<sz; i++) {
    for(int j=i+1; j<sz; j++) {
      if(tnodes[j].second - tnodes[i].second > d) break;
      d = min(d, dist(tnodes[i], tnodes[j]));
    }
  }
  return d;
}

int main() {
  while(scanf("%d", &n), n) {
    nodes.resize(n);
    tnodes.resize(n);
    double x, y;
    for(int i=0; i<n; i++) {
      scanf("%lf %lf", &x, &y);
      nodes[i] = ii(x, y);
    }
    sort(nodes.begin(), nodes.end());
    double ans = divide_solve(0, n-1);
    if(ans >= 10000) printf("INFINITY\n");
    else printf("%.4f\n", ans);
  }
  return 0;
}
