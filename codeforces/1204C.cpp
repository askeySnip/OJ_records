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
int n, m;
string s;
int g[105][105];
int p[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i, 0, 105) {
    REP(j, 0, 105) {
      g[i][j] = inf;
    }
  }
  REP(i, 0, 105) g[i][i] = 0;
  REP(i, 1, n+1) {
    cin >> s;
    REP(j, 0, s.length()) {
      if(s[j] == '1') g[i][j+1] = 1;
    }
  }
  REP(k, 1, n+1) {
    REP(i, 1, n+1) {
      REP(j, 1, n+1) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  cin >> m;
  REP(i, 0, m) cin >> p[i];
  vi ans;
  ans.push_back(p[0]);
  int pre = p[0];
  REP(i, 1, m-1) {
    if(g[pre][p[i+1]] == g[pre][p[i]] + g[p[i]][p[i+1]]) {
      continue;
    } else {
      ans.push_back(p[i]);
    }
    pre = p[i];
  }
  ans.push_back(p[m-1]);
  cout << ans.size() << endl;
  REP(i, 0, ans.size()) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
