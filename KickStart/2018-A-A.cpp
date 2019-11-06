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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

ll solve(ll n) {
  string s = to_string(n);
  // cout << "s : " << s << endl;
  int i;
  for (i = 0; i < s.length(); i++) {
    if ((s[i] - '0') % 2) {
      break;
    }
  }
  if (i == s.length()) return 0;
  ll ans = 1e18;
  ll t1 = 0, t2 = 0;
  for (int j = 0; j < s.length(); j++) {
    if (j < i) {
      t1 = t1 * 10 + s[j] - '0';
      t2 = t2 * 10 + s[j] - '0';
    } else if (j == i) {
      t1 = t1 * 10 + s[j] - '0' + 1;
      int base = 10;
      while ((t1 / base) % 2) {
        t1 += base;
        base *= 10;
      }
      t2 = t2 * 10 + s[j] - '0' - 1;
      base = 10;
      while ((t2 / base) % 2) {
        t2 -= base;
        base *= 10;
      }
      t2 += solve(t2);
    } else {
      t1 = t1 * 10;
      t2 = t2 * 10 + 8;
    }
  }
  // cout << t1 << " " << t2 << endl;
  return min(ans, min(t1 - n, n - t2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  ll n;
  cin >> t;
  int kase = 0;
  while (t--) {
    cin >> n;
    cout << "Case #" << ++kase << ": " << solve(n) << endl;
  }
  return 0;
}
