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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
struct ant {
  int x, s;
  int l, r;
};

// data
int n, m;
ant a[100];
int dp[100010];

void solve() {
  dp[m] = 0;
  for (int pos = m - 1; pos >= 0; pos--) {
    dp[pos] = m - pos;
    REP(i, 0, n) {
      int l = a[i].l, r = a[i].r;
      if (l <= pos + 1 && pos + 1 <= r) {
        dp[pos] = dp[pos + 1];
        break;
      }
      if (pos < l) {
        int u = l - pos - 1;
        dp[pos] = min(u + dp[min(m, r + u)], dp[pos]);
      }
    }
  }
  printf("%d\n", dp[0]);
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d%d", &n, &m);
    REP(i, 0, n) {
      scanf("%d%d", &a[i].x, &a[i].s);
      a[i].l = max(0, a[i].x - a[i].s);
      a[i].r = min(m, a[i].x + a[i].s);
    }
    solve();
  }
  return 0;
}
