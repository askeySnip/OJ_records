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
int b[100024], g[100024];
bitset<100024> bs;

bool check(int mx) {
  REP(i, 0, m) {
    if(g[i] < mx) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  int mx = 0;
  REP(i, 0, n) cin >> b[i], mx = max(mx, b[i]);
  REP(i, 0, m) cin >> g[i];
  if(!check(mx)) cout << -1 << endl;
  else {
    ll ans  = 0;
    REP(i, 0, n) ans += (ll)b[i] * m;
    sort(g, g+m);
    sort(b, b+n);
    int cur = n-1;
    for(int i=m-1; i>=0;) {
      for(int j=1; j<m; j++) {
        while(i >= 0 && g[i] == b[cur]) i--;
        if(i < 0) break;
        ans += g[i] - b[cur];
        i--;
        if(i < 0) break;
      }
      while(i >= 0 && g[i] == b[cur]) i--;
      cur--;
    }
    cout << ans << endl;
  }
  return 0;
}
