/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, n, k;
  char s[200048];
  int dp[3][200048];
  cin >> q;
  while(q--) {
    cin >> n >> k;
    cin >> (s+1);
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    REP(i, 1, n+1) {
      dp[0][i] = dp[2][i-1] + (s[i] != 'R');
      dp[1][i] = dp[0][i-1] + (s[i] != 'G');
      dp[2][i] = dp[1][i-1] + (s[i] != 'B');
    }
    int ans = 1e6;
    REP(i, k, n+1) {
      ans = min(dp[0][i] - dp[k%3 == 0 ? 0 : (k%3 == 1 ? 2 : 1)][i-k], ans);
      ans = min(dp[1][i] - dp[k%3 == 0 ? 1 : (k%3 == 1 ? 0 : 2)][i-k], ans);
      ans = min(dp[2][i] - dp[k%3 == 0 ? 2 : (k%3 == 1 ? 1 : 0)][i-k], ans);
    }
    cout << ans << endl;
  }
  return 0;
}
