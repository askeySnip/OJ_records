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

// struct
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// data
char s[110];
int len;
int dp[110][110][110];
bool op[110][110][110];

int solve() {
  len = strlen(s + 1);
  REP(i, 0, len + 1) REP(j, 0, len + 1) REP(k, 0, len + 1) dp[i][j][k] = 300;
  memset(op, 0, sizeof op);
  dp[1][1][0] = 1;
  REP(i, 1, len + 1) {
    REP(j, 1, len + 1) { op[i][j][1] = s[i] == s[j]; }
  }
  REP(l, 2, len + 1) {
    for (int i = 1; i + l - 1 <= len; i++) {
      for (int j = 1; j <= len; j++) {
        op[i][j][l] = op[i][j][l - 1] && s[i + l - 1] == s[j + l - 1];
      }
    }
  }
  REP(i, 1, len + 1) {
    int c = inf;
    for (int j = 1; j <= i; j++) {
      for (int l = 0; j + l - 1 <= i; l++) {
        c = min(c, dp[i][j][l]);
      }
    }
    if (i == len) {
      return c;
    }
    for (int j = 1; j <= i; j++) {
      for (int l = 1; j + l - 1 <= i; l++) {
        dp[i][j][l] = min(dp[i][j][l], c + 1);
      }
    }
    for (int j = 1; j <= i; j++) {
      for (int l = 0; j + l - 1 <= i; l++) {
        if (op[i + 1][j][l]) {
          dp[i + l][j][l] = min(dp[i + l][j][l], dp[i][j][l] + 1);
        }
        dp[i + 1][j][l] = min(dp[i + 1][j][l], dp[i][j][l] + 1);
      }
    }
  }
  return 0;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    printf("Case #%d: %d\n", ++kase, solve());
  }

  return 0;
}
