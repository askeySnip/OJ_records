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
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int n, m;
int a[122], b[122];
vi edges[223];
vi match, vis;

int Aug(int l) {
  if(vis[l]) return 0;
  vis[l] = 1;
  REP(i, 0, edges[l].size()) {
    int r = edges[l][i];
    if(match[r] == -1 || Aug(match[r])) {
      match[r] = l;
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while (t--) {
    REP(i, 0, 223) edges[i].clear();
    scanf("%d", &n);
    REP(i, 0, n) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    REP(i, 0, m) scanf("%d", &b[i]);
    REP(i, 0, n) {
      REP(j, 0, m) {
        if ((a[i] != 0 && b[j] % a[i] == 0) || (a[i] == b[j])) { // notice: a[i] && b[i] maybe 0!!!! so check is needed.
          edges[i].push_back(j+n);
          edges[j+n].push_back(i);
        }
      }
    }
    int MCBM = 0;
    match.assign(n+m+3, -1);
    REP(i, 0, n) {
      vis.assign(n, 0);
      MCBM += Aug(i);
    }
    printf("Case %d: %d\n", ++kase, MCBM);
  }
  return 0;
}
