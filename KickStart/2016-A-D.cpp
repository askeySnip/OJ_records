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
typedef vector<pair<int, int>> vii;
typedef long long ll;

// struct
#define mp make_pair
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;
const double eps = 1e-14;
const ll llinf = 1e14;

struct card {
  int k, l;
  int a[11];
  int c[11];
};

// data
int m, n;
card cd[13];
vector<pair<ll, ll>> tp[2];
// map<ii, ll> tot;

// ll dp(int mask, int p) {
//   if (mask == 0) return 0;
//   if (tot.find(ii(mask, p)) != tot.end()) return tot[ii(mask, p)];
//   int id = 0;
//   for (; id < n; id++) {
//     if (mask & (1 << id)) {
//       break;
//     }
//   }
//   ll ret = 0;
//   ll cost = 0;
//   int nxt = mask - (mask & (-mask));
//   for (int i = cd[id].l; i <= cd[id].k; i++) {
//     if (p < cost) break;
//     ret = max(ret, dp(nxt, p - cost) + cd[id].a[i]);
//     if (i < cd[id].k) cost += cd[id].c[i];
//   }
//   return tot[ii(mask, p)] = ret;
// }

void dfs(int mask, ll cst, ll att, int flag) {
  if (mask == 0) {
    tp[flag].push_back(mp(cst, att));
    return;
  }
  int id = 0;
  for (; id < n; id++) {
    if (mask & (1 << id)) {
      break;
    }
  }
  ll ret = 0;
  ll cost = 0;
  int nxt = mask - (mask & (-mask));
  for (int i = cd[id].l; i <= cd[id].k; i++) {
    dfs(nxt, cst + cost, att + cd[id].a[i], flag);
    if (i < cd[id].k) cost += cd[id].c[i];
  }
}

void go(int mask, int flag) {
  REP(i, 0, n) {
    if (mask & (1 << i)) {
      dfs(mask, 0, 0, flag);
      break;
    }
  }
  sort(tp[flag].begin(), tp[flag].end());
  REP(i, 1, tp[flag].size()) {
    tp[flag][i].second = max(tp[flag][i - 1].second, tp[flag][i].second);
  }
}

ll solve() {
  ll ans = 0;
  REP(i, 0, (1 << n)) {
    if (__builtin_popcount(i) == 8) {
      // int id = 0;
      // while (i & (1 << id) == 0) id++;
      // ans = max(ans, dp(i, m));
      int pre = 0, cnt = 0;
      REP(j, 0, n) {
        if (i & (1 << j)) {
          pre |= (1 << j);
          cnt++;
        }
        if (cnt == 4) break;
      }
      int last = i - pre;
      tp[0].clear();
      tp[1].clear();
      go(pre, 0);
      go(last, 1);
      int k = tp[1].size() - 1;
      REP(j, 0, tp[0].size()) {
        if (tp[0][j].first > m) break;
        while (k >= 0 && tp[0][j].first + tp[1][k].first > m) k--;
        if (k >= 0)
          ans = max(ans, tp[0][j].second + tp[1][k].second);
        else
          ans = max(ans, tp[0][j].second);
      }
      REP(j, 0, tp[1].size()) {
        if (tp[1][j].first <= m)
          ans = max(ans, tp[1][j].second);
        else
          break;
      }
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    // tot.clear();
    scanf("%d%d", &m, &n);
    REP(i, 0, n) {
      scanf("%d%d", &cd[i].k, &cd[i].l);
      REP(j, 1, cd[i].k + 1) { scanf("%d", &cd[i].a[j]); }
      REP(j, 1, cd[i].k) { scanf("%d", &cd[i].c[j]); }
    }
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
