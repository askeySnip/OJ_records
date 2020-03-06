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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
string a;
int p, k, s;
string d[7];
int dp[220][220];
int dp2[42][220];

int main() {
  cin >> p >> k;
  REP(i, 0, p) {
    string t;
    cin >> t;
    a += t;
  }
  cin >> s;
  REP(i, 0, s) cin >> d[i];
  memset(dp, 0, sizeof dp);
  memset(dp2, 0, sizeof dp2);
  REP(l, 1, a.length() + 1) {
    REP(i, 0, a.length() - l + 1) {
      int j = i + l - 1;
      REP(ii, 0, s) {
        auto pos = a.substr(i, l).find(d[ii]);
        if (pos != string::npos) {
          dp[i][j] = max(dp[i][j], dp[i + pos + 1][j] + 1);
        }
      }
    }
  }
  REP(i, 0, a.length()) dp2[1][i] = dp[0][i];
  REP(i, 2, k + 1) {
    REP(j, i - 1, a.length()) {
      REP(jj, i - 2, j) {
        dp2[i][j] = max(dp2[i][j], dp2[i - 1][jj] + dp[jj + 1][j]);
      }
    }
  }
  printf("%d\n", dp2[k][a.length() - 1]);
  return 0;
}
