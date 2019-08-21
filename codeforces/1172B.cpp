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
const int mod = 998244353;
// data
int n;
int degree[200024];
ll f[200024];

void init() {
  f[1] = 1;
  REP(i, 2, n+1) {
    f[i] = f[i-1] * i;
    f[i] %= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  init();
  int u, v;
  memset(degree, 0, sizeof degree);
  REP(i, 1, n) {
    cin >> u >> v;
    degree[u]++;
    degree[v]++;
  }
  ll ans = n;
  REP(i, 1, n+1) {
    ans *= f[degree[i]];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
