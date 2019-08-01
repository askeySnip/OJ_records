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
ll bst[300048];

ll sum(int l, int r) {
  l = max(l, 0);
  return s[r] - (l == 0 ? 0 : s[l-1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  REP(i, 0, n) {
    cin >> a[i];
    s[i] = a[i] + (i == 0 ? 0 : s[i-1]);
  }
  ll ans = 0;
  for(int len = 1; len <= m && len <= n; len++) {
    ans = max(ans, sum(0, len-1) - k);
  }
  for(int i=0; i<n; i++) {
    if(i+1 >= m) {
      ll nbst = sum(i - m + 1, i) - k;
      if(i - m >= 0) nbst += bst[i - m];
      bst[i] = max(bst[i], nbst);
    }
    for(int len = 0; len < m && i + len < n; len++) {
      ans = max(ans, bst[i] + sum(i+1, i+len) - k * (len > 0));
    }
  }

  cout << ans << endl;
  return 0;
}
