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
const int inf = 0x3ffffff;
const int mod = 1e9 + 7;

// struct

// data
int n, m;
int a[2020][2020];
int dp[2020][2020];
int h[2020], stk[2020];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, n) REP(j, 0, m) scanf("%d", &a[i][j]);
  int ans1 = 0, ans2 = 0;
  REP(i, 0, n) dp[i][0] = 1;
  REP(i, 0, m) dp[0][i] = 1;
  REP(i, 1, n)
  REP(j, 1, m) {
    if (a[i][j] == a[i - 1][j - 1] && a[i][j] != a[i - 1][j] &&
        a[i][j] != a[i][j - 1])
      dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
    else
      dp[i][j] = 1;
    ans1 = max(ans1, dp[i][j] * dp[i][j]);
  }
  REP(i, 0, n) {
    REP(j, 0, m) {
      if (i && a[i][j] != a[i - 1][j])
        h[j]++;
      else
        h[j] = 1;
    }
    int pos = 0;
    stk[pos] = -1;
    REP(j, 0, m) {
      if (pos && a[i][j] == a[i][stk[pos]]) {
        while (pos > 0) {
          ans2 = max(ans2, (j - stk[pos - 1] - 1) *
                               h[stk[pos]]);  // notice (j - stk[pos-1] - 1);
          pos--;
        }
        stk[pos] = j - 1;  // notice.
      }
      while (pos > 0 && h[j] < h[stk[pos]]) {
        ans2 = max(ans2, h[stk[pos]] * (j - stk[pos]));
        pos--;
      }
      stk[++pos] = j;
    }
    while (pos > 0) {
      ans2 = max(ans2, (m - stk[pos - 1] - 1) * h[stk[pos]]);
      pos--;
    }
  }
  printf("%d\n%d\n", ans1, ans2);
  return 0;
}
