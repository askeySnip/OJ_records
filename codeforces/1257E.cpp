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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int k1, k2, k3;
int a[200010];
int dp[200010][3];

void solve() {
  int n = k1 + k2 + k3;
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  REP(i, 1, n + 1) {
    dp[i][0] = (a[i] == 0 ? 0 : 1) + dp[i - 1][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (a[i] == 1 ? 0 : 1);
    dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) +
               (a[i] == 2 ? 0 : 1);
  }
  printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d%d%d", &k1, &k2, &k3);
    int t = 0;
    REP(i, 0, k1) scanf("%d", &t), a[t] = 0;
    REP(i, 0, k2) scanf("%d", &t), a[t] = 1;
    REP(i, 0, k3) scanf("%d", &t), a[t] = 2;
    solve();
  }

  return 0;
}
