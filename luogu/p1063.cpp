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

// data
int n;
int a[110];
ii b[220];
ll dp[220][220];

ll dfs(int l, int r) {
  if (l == r) return 0;
  if (l == r - 1) return b[l].first * b[l].second * b[r].second;
  if (dp[l][r] != -1) return dp[l][r];
  ll ret = 0;
  for (int i = l; i < r; i++) {
    ret = max(ret, dfs(l, i) + dfs(i + 1, r) +
                       1LL * b[l].first * b[i].second * b[r].second);
  }
  return dp[l][r] = ret;
}

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  a[n] = a[0];
  REP(i, 0, n) b[i] = ii(a[i], a[i + 1]), b[i + n] = b[i];
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  REP(i, 0, n) ans = max(ans, dfs(i, i + n - 1));
  printf("%lld\n", ans);
  return 0;
}
