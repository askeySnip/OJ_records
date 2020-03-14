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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n, m, K;
int s1[110], s2[110], dp[110][110], f[110][110][13];

int main() {
  scanf("%d%d%d", &n, &m, &K);
  if (m == 1) {
    int x;
    REP(i, 1, n + 1) scanf("%d", &x), s1[i] = s1[i - 1] + x;
    for (int k = 1; k <= K; k++) {
      for (int i = 1; i <= n; i++) {
        dp[i][k] = dp[i - 1][k];
        for (int j = 0; j < i; j++)
          dp[i][k] = max(dp[i][k], dp[j][k - 1] + s1[i] - s1[j]);
      }
    }
    printf("%d\n", dp[n][K]);
  } else {
    int x, y;
    for (int i = 1; i <= n; i++)
      scanf("%d%d", &x, &y), s1[i] = s1[i - 1] + x, s2[i] = s2[i - 1] + y;
    for(int k=1; k<=K; k++){ 
      for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
          f[i][j][k] = max(f[i-1][j][k], f[i][j-1][k]);
          for (int l = 0; l < i; l++)
            f[i][j][k] = max(f[i][j][k], f[l][j][k - 1] + s1[i] - s1[l]);
          for (int l = 0; l < j; l++)
            f[i][j][k] = max(f[i][j][k], f[i][l][k - 1] + s2[j] - s2[l]);
          if (i == j)
            for (int l = 0; l < i; l++)
              f[i][j][k] = max(f[i][j][k],
                               f[l][l][k - 1] + s1[i] - s1[l] + s2[j] - s2[l]);
        }
      }
    }
    printf("%d\n", f[n][n][K]);
  }
  return 0;
}
