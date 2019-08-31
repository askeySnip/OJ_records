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
int n;
int op[300024], f[300024];
int dp[300024];
vi child[300024];
int k;

int g(int t) {
  if(dp[t]) return dp[t];
  if(child[t].empty()) return 1;
  int ret;
  if(op[t]) {
    ret = inf;
    REP(i, 0, child[t].size()) {
      int v = child[t][i];
      ret = min(ret, g(v));
    }
  } else {
    ret = 0;
    REP(i, 0, child[t].size()) {
      int v = child[t][i];
      ret += g(v);
    }
  }
  return dp[t] = ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, 1, n+1) cin >> op[i];
  REP(i, 2, n+1) cin >> f[i], child[f[i]].push_back(i);
  k = 0;
  REP(i, 1, n+1) {
    if(child[i].empty()) k++;
  }
  cout << k - g(1) + 1 << endl;
  return 0;
}
