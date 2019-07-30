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
int n, m, k;
int a[300048];
ll s[300048];
ll maxsm[300048];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  REP(i, 1, n+1) cin >> a[i];
  s[0] = 0L;
  REP(i, 1, n+1) {
    s[i] = s[i-1] + a[i];
  }
  REP(i, m, n+1) {
    maxsm[i] = 0L;
    REP(j, 0, m) {
      maxsm[i] = max(maxsm[i], s[i-j] - s[i-m]);
    }
  }
  REP(i, m, n+1) cout << s[i] << " ";
  cout << endl;
  REP(i, m, n+1) cout << maxsm[i] << " ";
  cout << endl;
  ll ans = 0;
  for(int j=m; j<2*m; j++) {
    ll cur = 0;
    for(int i=j; i<=n; i+=m) {
      ll t = cur + (maxsm[i] - k);
      ans = max(ans, t);
      cur += s[i] - s[i-m] - k;
      if(cur < 0L) cur = 0L;
    }
  }
  cout << ans << endl;
  return 0;
}
