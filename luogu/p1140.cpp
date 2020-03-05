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
int m, n;
char a[110], b[110];
int dp[110][110];

int main() {
  map<pair<char, char>, int> mp1{{{'A', 'C'}, -1}, {{'A', 'G'}, -2},
                                 {{'A', 'T'}, -1}, {{'C', 'G'}, -3},
                                 {{'C', 'T'}, -2}, {{'G', 'T'}, -2}};
  map<char, int> mp2{{'A', -3}, {'C', -4}, {'G', -2}, {'T', -1}};
  scanf("%d %s", &m, a + 1);
  scanf("%d %s", &n, b + 1);
  memset(dp, 0, sizeof dp);
  REP(i, 1, m+1) dp[0][i] = dp[0][i-1] + mp2[b[i]];
  REP(j, 1, n+1) dp[j][0] = dp[j-1][0] + mp2[a[j]];
  REP(i, 1, m + 1) {
    REP(j, 1, n + 1) {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 5;
      else {
        dp[i][j] =
            max(max(dp[i - 1][j] + mp2[a[i]], dp[i][j - 1] + mp2[b[j]]),
                dp[i - 1][j - 1] + mp1[{min(a[i], b[j]), max(a[i], b[j])}]);
      }
    }
  }
  printf("%d\n", dp[m][n]);
  return 0;
}
