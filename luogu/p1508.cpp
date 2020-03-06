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
int m, n;
int dp[210][210];

int main() {
  scanf("%d%d", &m, &n);
  memset(dp, 0, sizeof dp);
  REP(i, 1, m + 1) REP(j, 1, n + 1) scanf("%d", &dp[i][j]);
  REP(i, 2, m + 1) {
    REP(j, 1, n + 1) {
      dp[i][j] =
          max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + dp[i][j];
    }
  }
  int t = n / 2 + 1;
  printf("%d\n", max(dp[m][t], max(dp[m][t - 1], dp[m][t + 1])));
  return 0;
}
