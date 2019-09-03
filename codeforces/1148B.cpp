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
int n, m, ta, tb, k;
int a[200024], b[200024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> ta >> tb >> k;
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, m) cin >> b[i];
  if(k >= min(n, m)) {
    cout << -1 << endl;
    return 0;
  }
  // int pos = lower_bound(b, b+m, a[0]+ta) - b;
  // int ans = b[pos+k];
  int ans = 0;
  REP(i, -1, k) {
    int pos = lower_bound(b, b+m, a[i+1]+ta) - b;
    if(m - pos <= k - i - 1) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, b[pos + k - i - 1] + tb);
  }
  cout << ans << endl;
  return 0;
}
