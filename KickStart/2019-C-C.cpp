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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, k;
vii dogs;
int dp[2][1024][1024];
int dog_col[1024][1024];

int solve() {
  REP(i, 0, 1024) {
    REP(j, 0, 1024) { dog_col[i][j] = inf; }
  }
  int id = 0, cur = dogs[0].first, c = 0;
  REP(i, 0, n) {
    if (dogs[i].first == cur) {
      dog_col[id][c++] = dogs[i].second * 2;
    } else {
      cur = dogs[i].first;
      id++;
      c = 0;
      dog_col[id][c++] = dogs[i].second * 2;
    }
  }
  id++;
  REP(i, 1, k + 1) {
    dp[0][0][i] = dog_col[0][i - 1];
    dp[1][0][i] = dog_col[0][i - 1] / 2;
  }
  dp[1][0][0] = 0;
  dp[0][0][0] = 0;
  REP(i, 1, id) {
    REP(j, 1, k + 1) {
      dp[0][i][j] = dp[0][i - 1][j];
      dp[1][i][j] = dp[1][i - 1][j];
      REP(m, 1, j + 1) {
        dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j - m] + dog_col[i][m - 1]);
        dp[1][i][j] =
            min(dp[1][i][j], min(dp[0][i - 1][j - m] + dog_col[i][m - 1] / 2,
                                 dp[1][i - 1][j - m] + dog_col[i][m - 1]));
      }
    }
  }
  return dp[1][id - 1][k];
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    dogs.resize(n);
    REP(i, 0, n) scanf("%d", &dogs[i].second);
    REP(i, 0, n) scanf("%d", &dogs[i].first);
    sort(dogs.begin(), dogs.end());
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
