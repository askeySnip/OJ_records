/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int a[10];
int dp[10][500][11];
void solve() {
  memset(dp, 0, sizeof dp);
  for (int i = 1; i < 10; i++) {
    if (a[i] > 20) a[i] = 20 + (a[i] & 1);
  }
  dp[0][0][0] = 1;
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j <= a[i]; j++) {
      for (int k = 0; k + j < 500; k++) {
        int nmod = (j * i - (a[i] - j) * i) % 11;
        nmod = (nmod + 11) % 11;
        for (int m = 0; m < 11; m++) {
          dp[i][j + k][(m + nmod) % 11] |= dp[i - 1][k][m];
        }
      }
    }
  }
  int s = 0;
  for (int i = 1; i < 10; i++) s += a[i];
  if (dp[9][s / 2][0])
    printf("YES\n");
  else
    printf("NO\n");
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    REP(i, 1, 10) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
