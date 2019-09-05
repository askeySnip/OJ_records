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
const ll llinf = 1e18;
int n, a, b;
char s[200005];
ll dp[2][200005];
void solve() {
  dp[0][0] = 0;
  dp[1][0] = llinf;
  REP(i, 1, n) {
    if(s[i] != s[i+1] && s[i] == '0') {
      dp[0][i] = llinf;
      dp[1][i] = min(dp[1][i-1] + a, dp[0][i-1] + 2 * a) + 2 * b;
    } else if(s[i] != s[i-1] && s[i] == '0') {
      dp[0][i] = dp[1][i-1] + 2 * a + b;
      dp[1][i] = dp[1][i-1] + a + 2 * b;
    } else{
      dp[0][i] = dp[0][i-1] + a + b;
      dp[1][i] = dp[1][i-1] + a + 2 * b;
    }
  }
  cout << (dp[0][n-1] + a + b > dp[1][n-1] + 2 * a + b ? dp[1][n-1] + 2 * a + b : dp[0][n-1] + a + b) + b << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  s[0] = '0';
  while(t--) {
    cin >> n >> a >> b;
    cin >> (s+1);
    solve();
  }
  return 0;
}
