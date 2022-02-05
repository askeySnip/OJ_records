/*
AUTHOR: ZhenLee
CREATED: 2021.08.22
LANG: C++14
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  REP(i, 0, n) cin >> a[i];
  vector<vector<vi>> dp(n, vector<vi>(n, vi(2, inf)));
  //   cout << "asdfasdf" << endl;
  REP(i, 0, n) dp[i][i][0] = dp[i][i][1] = 0;
  REP(l, 2, n + 1) {
    REP(i, 0, n - l + 1) {
      int j = i + l - 1;
      dp[i][j][0] = min(dp[i + 1][j][0] + abs(a[i + 1] - a[i]),
                        dp[i + 1][j][1] + abs(a[j] - a[i]));
      dp[i][j][1] = min(dp[i][j - 1][0] + abs(a[i] - a[j]),
                        dp[i][j - 1][1] + abs(a[j - 1] - a[j]));
    }
  }
  cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
  return 0;
}
