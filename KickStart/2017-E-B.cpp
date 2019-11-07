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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
class BIT {
 private:
  vi ft;

 public:
  BIT(int n) { ft.assign(n + 1, 0); }
  void add(int k, int v) {
    for (; k < ft.size(); k += (k & (-k))) ft[k] += v;
  }
  int sum(int k) {
    int ret = 0;
    for (; k; k -= (k & (-k))) ret += ft[k];
    return ret;
  }
};

// data
int n;
map<int, int> cnt;

ll solve() {
  ll ans = 0;
  BIT bt(n + 1);
  vector<ll> a;
  a.push_back(0);
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    bt.add(a.size(), it->second);
    a.push_back(it->first);
  }
  // cout << a.size() << endl;
  REP(i, 1, a.size()) {
    if (cnt[a[i]] > 1) {
      bt.add(i, -cnt[a[i]]);
      ll t = cnt[a[i]] * (cnt[a[i]] - 1) / 2;
      REP(j, 1, a.size()) {
        if (i == j) continue;
        auto id = lower_bound(a.begin(), a.end(), a[j] + 2 * a[i]) - a.begin();
        ans += t * cnt[a[j]] * (bt.sum(id - 1) - bt.sum(j));
      }
      if (cnt[a[i]] > 2) {
        auto id = lower_bound(a.begin(), a.end(), a[i] * 3) - a.begin();
        ans += 1LL * (cnt[a[i]] - 1) * cnt[a[i]] * (cnt[a[i]] - 2) / 6 *
               bt.sum(id - 1);
      }
      bt.add(i, cnt[a[i]]);
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int l;
  while (t--) {
    cnt.clear();
    scanf("%d", &n);
    REP(i, 0, n) {
      scanf("%d", &l);
      cnt[l]++;
    }
    printf("Case #%d: %lld\n", ++kase, solve());
  }

  return 0;
}
