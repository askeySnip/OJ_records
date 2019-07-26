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
// datai
int n, T;
int t[16], g[16];
int dp[1 << 16][4];
const int mod = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> T;
  for(int i=0; i<n; i++) {
    cin >> t[i] >> g[i];
    g[i]--;
  }
  dp[0][3] = 1;
  int ans = 0;
  for(int mask=0; mask<(1<<n); mask++) {
    for(int lst=0; lst<4; lst++) {
      for(int i=0; i<n; i++) {
        if(g[i] != lst && ((mask & (1 << i)) == 0)) {
          dp[mask ^ (1 << i)][g[i]] = (dp[mask ^ (1 << i)][g[i]] + dp[mask][lst]) % mod;
        }
      }
      int sum = 0;
      for(int i=0; i<n; i++) {
        if(mask & (1 << i)) sum += t[i];
      }
      if(sum == T) ans = (ans + dp[mask][lst]) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
