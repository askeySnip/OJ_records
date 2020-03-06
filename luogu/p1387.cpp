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
int n, m;
int a[110][110];
int dp[110][110];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, n) REP(j, 0, m) scanf("%d", &a[i][j]);
  int ans = 0;
  REP(i, 0, n) dp[i][0] = a[i][0], ans = max(ans, dp[i][0]);
  REP(i, 0, m) dp[0][i] = a[0][i], ans = max(ans, dp[0][i]);
  REP(i, 1, n) {
    REP(j, 0, m) {
      if (a[i][j])
        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
      else
        dp[i][j] = 0;
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
