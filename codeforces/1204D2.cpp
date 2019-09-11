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
string s;
string ans;
int dp[2][100024];
int dp2[2][100024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  ans = s;
  REP(i, 0, ans.length()) {
    ans[i] = '0';
  }
  if(s.length() == 0) {
    cout << s << endl;
    return 0;
  }
  if(s[0] == '0') {
    dp[0][0] = 1;
  } else {
    dp[1][0] = 1;
  }
  dp2[0][0] = 1; dp2[1][0] = 0;
  REP(i, 1, s.length()) {
    if(s[i] == '0') dp[1][i] = dp[1][i-1], dp[0][i] = dp[0][i-1] + 1;
    else dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + 1, dp[0][i] = dp[0][i-1];
    dp2[0][i] = dp2[0][i-1] + 1;
    int ans_s = max(dp[0][i], dp[1][i]);
    int ans_t = max(dp2[0][i], dp2[1][i]);
    // cout << dp[0][i] << " " << dp[1][i] << " s" << endl;
    // cout << dp2[0][i] << " " << dp2[1][i] << " t" << endl;
    if(ans_s < ans_t) {
      // cout << "!!!" << endl;
      for(int j=i-1; j>=0; j--) {
        if(ans[j] == '0' && dp2[1][j] + 1 <= max(dp[0][j], dp[1][j])) {
          ans[j] = '1';
          break;
        }
      }
      dp2[0][i]--;
      dp2[1][i] = ans_s;
    }
  }
  cout << ans << endl;
  return 0;
}
