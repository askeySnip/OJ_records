/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int k, n;
vii xc;

ll solve() {
  int k1 = k / 2, k2 = k - k1;
  priority_queue<int> l;
  priority_queue<ii, vii, greater<ii>> r;
  set<int> s;
  ll tmp = xc[k1].second;
  for (int i = 0; i < k1; i++) {
    l.push(xc[i].second - xc[i].first);
    tmp += xc[i].second - xc[i].first;
  }
  for (int i = n - 1; i > k1; i--) {
    r.push(ii(xc[i].second + xc[i].first, i));
  }
  for (int i = 0; i < k2; i++) {
    ii p = r.top();
    r.pop();
    s.insert(p.second);
    tmp += p.first;
  }
  ll ans = tmp + 1LL * k1 * xc[k1].first - 1LL * k2 * xc[k1].first;
  for (int i = k1 + 1; i < n - k2; i++) {
    tmp -= xc[i - 1].second;
    tmp += xc[i].second;
    if (!l.empty() && xc[i - 1].second - xc[i - 1].first < l.top()) {
      tmp -= l.top();
      l.pop();
      tmp += xc[i - 1].second - xc[i - 1].first;
      l.push(xc[i - 1].second - xc[i - 1].first);
    }
    if (!s.empty()) {
      if (*s.begin() == i) {
        s.erase(s.begin());
        while (r.top().second <= i) r.pop();
        tmp -= xc[i].second + xc[i].first;
        tmp += r.top().first;
        s.insert(r.top().second);
        r.pop();
      }
    }
    ans = min(ans, tmp + 1LL * k1 * xc[i].first - 1LL * k2 * xc[i].first);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, kase = 0;
  cin >> t;
  while (t--) {
    cin >> k >> n;
    xc.resize(n);
    REP(i, 0, n) cin >> xc[i].first;
    REP(i, 0, n) cin >> xc[i].second;
    sort(xc.begin(), xc.end());
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
