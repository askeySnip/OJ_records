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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct
struct bign {
  int a[60];
  int len;
  bign() {
    len = 1;
    REP(i, 0, 60) a[i] = 0;
  }
  bign(int x) {
    len = 1;
    while (x) {
      a[len++] = x % 10;
      x /= 10;
    }
    REP(i, len, 60) a[i] = 0;
  }
  bign(const bign& b) {
    len = b.len;
    REP(i, 0, 60) a[i] = b.a[i];
  }
  bign& operator=(const bign& b) {
    len = b.len;
    REP(i, 0, 60) a[i] = b.a[i];
    return *this;
  }
};

// data
int n, m;
int r[90];
bign pow2[100];
vector<vector<bign>> dp;
bign ans;

void multi(bign& a, int b, bign& c) {
  for (int i = 1; i <= a.len; i++) {
    c.a[i] = a.a[i] * b;
  }
  for (int i = 1; i <= a.len + 5; i++) {
    if (c.a[i]) c.len = i;
    if (c.a[i] >= 10) {
      c.a[i + 1] += c.a[i] / 10;
      c.a[i] %= 10;
    }
  }
}

bign max_bign(bign& a, bign& b) {
  if (a.len != b.len) {
    return a.len > b.len ? a : b;
  }
  for (int i = a.len; i >= 1; i--) {
    if (a.a[i] != b.a[i]) {
      return a.a[i] > b.a[i] ? a : b;
    }
  }
  return a;
}

void add(bign& a, bign& b) {
  int l = max(a.len, b.len);
  for (int i = 1; i <= l + 2; i++) {
    a.a[i] += b.a[i];
    if (a.a[i] >= 10) {
      a.a[i + 1] += a.a[i] / 10;
      a.a[i] %= 10;
    }
    if (a.a[i]) a.len = i;
  }
}

void solve() {
  REP(i, 0, m) dp[i][i] = bign(r[i] * 2);
  REP(l, 2, m + 1) {
    REP(i, 0, m - l + 1) {
      int j = i + l - 1;
      bign ll = bign(0), rr = bign(0);
      bign lv(r[i] * 2), rv(r[j] * 2);
      multi(dp[i + 1][j], 2, ll);
      multi(dp[i][j - 1], 2, rr);
      add(ll, lv);
      add(rr, rv);
      dp[i][j] = max_bign(ll, rr);
    }
  }
  add(ans, dp[0][m - 1]);
}

int main() {
  scanf("%d%d", &n, &m);
  dp.assign(m, vector<bign>(m));
  REP(i, 0, 100) { pow2[i].len = 0; }
  pow2[0].a[1] = 1;
  pow2[0].len = 1;
  ans = bign(0);
  REP(i, 1, 100) { multi(pow2[i - 1], 2, pow2[i]); }
  REP(i, 0, n) {
    REP(j, 0, m) scanf("%d", &r[j]);
    solve();
  }
  for (int i = ans.len; i >= 1; i--) {
    printf("%d", ans.a[i]);
  }
  printf("\n");
  return 0;
}
