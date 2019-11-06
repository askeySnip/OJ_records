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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int n, k;
double v[20024];
double sm[20024];
double dp[50003];

double solve() {
  double s = 0;
  sort(v, v + n);
  sm[0] = v[0];
  for (int i = 1; i < n; i++) {
    sm[i] = sm[i - 1] + v[i];
  }
  dp[0] = sm[n - 1] * 1.0 / n;
  for (int i = 1; i <= k; i++) {
    int idx = upper_bound(v, v + n, dp[i - 1]) - v;
    // cout << idx << " " << dp[i-1] << endl;
    dp[i] = sm[n - 1] - sm[idx - 1];
    dp[i] /= n;
    dp[i] += idx * 1.0 / n * dp[i - 1];
  }
  return dp[k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int kase = 0;
  while (t--) {
    cin >> n >> k;
    REP(i, 0, n) { cin >> v[i]; }
    printf("Case #%d: %.6f\n", ++kase, solve());
  }
  return 0;
}
