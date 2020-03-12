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
int n;
ii p[210];
int dp[210][210 * 210];  // 前i个人在1号窗口总打饭时间为j的最早吃完饭时间
int s[210];

bool cmp(ii a, ii b) { return a.second > b.second; }

int main() {
  scanf("%d", &n);
  REP(i, 1, n + 1) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p + 1, p + n + 1, cmp);
  REP(i, 1, n + 1) s[i] = s[i - 1] + p[i].first;
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  REP(i, 1, n + 1) {
    REP(j, 0, s[n] + 1) {
      if (j >= p[i].first)
        dp[i][j] =
            min(dp[i][j], max(dp[i - 1][j - p[i].first], j + p[i].second));
      dp[i][j] = min(dp[i][j], max(dp[i - 1][j], s[i] - j + p[i].second));
    }
  }
  int ans = 2e9;
  REP(i, 0, s[n] + 1) { ans = min(ans, dp[n][i]); }
  printf("%d\n", ans);
  return 0;
}
