/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct
struct o {
  int w, v, f;
};

// data
int n, m;
o a[66];
int f[66][3];
int dp[33000];

int main() {
  int v, p, q;
  scanf("%d%d", &n, &m);
  REP(i, 1, m + 1) {
    scanf("%d%d%d", &v, &p, &q);
    a[i].w = v, a[i].v = v * p, a[i].f = q;
    if (q) f[q][0] ? f[q][1] = i : f[q][0] = i;
  }
  REP(i, 1, m + 1) {
    for (int j = n; j >= a[i].w; j--) {
      if (a[i].f) continue;
      dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
      int x = f[i][0], y = f[i][1];
      if (x && j >= a[i].w + a[x].w) {
        dp[j] = max(dp[j], dp[j - a[i].w - a[x].w] + a[i].v + a[x].v);
      }
      if (y && j >= a[i].w + a[y].w) {
        dp[j] = max(dp[j], dp[j - a[i].w - a[y].w] + a[i].v + a[y].v);
      }
      if (x && y && j >= a[i].w + a[x].w + a[y].w) {
        dp[j] = max(
            dp[j], dp[j - a[i].w - a[x].w - a[y].w] + a[i].v + a[x].v + a[y].v);
      }
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
