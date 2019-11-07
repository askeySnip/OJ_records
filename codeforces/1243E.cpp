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

// data
int n;
vi a[16];
ll sumBox[16];
map<ll, int> boxId;
bool trueMask[1 << 16];
bool dp[1 << 16];
vii cycle[1 << 16];
int cpnt[1 << 16];
vii ans;

void getAns(int mask) {
  if (!trueMask[mask]) {
    getAns(cpnt[mask]);
    getAns(mask ^ cpnt[mask]);
  } else {
    int sz = cycle[mask].size();
    REP(i, 0, cycle[mask].size()) {
      ii p = cycle[mask][i];
      // cout << "a " << p.first << " " << p.second << endl;
      ans[p.first] = mp(p.second, cycle[mask][(i - 1 + sz) % sz].first + 1);
    }
  }
}

void solve() {
  ll avg = 0;
  REP(i, 0, n) { sort(a[i].begin(), a[i].end()); }
  REP(i, 0, n) {
    REP(j, 0, a[i].size()) {
      avg += a[i][j];
      sumBox[i] += a[i][j];
      boxId[a[i][j]] = i;
    }
  }
  if (avg % n) {
    printf("No\n");
    return;
  }
  avg /= n;
  memset(trueMask, 0, sizeof trueMask);
  REP(i, 0, n) {
    REP(j, 0, a[i].size()) {
      int mask = 0;
      int curBox = i, lastVal = a[i][j];
      bool firstTurn = true, bad = false;
      vii tmp;
      while (firstTurn || curBox != i) {
        if (mask & (1 << curBox)) {
          bad = true;
          break;
        }
        firstTurn = 0;
        mask |= (1 << curBox);
        tmp.push_back(mp(curBox, lastVal));
        ll needVal = avg - sumBox[curBox] + lastVal;
        if (boxId.count(needVal) == 0) {
          bad = true;
          break;
        }
        curBox = boxId[needVal];
        lastVal = needVal;
      }
      if (!bad) {
        if (lastVal == a[i][j]) {
          if (!trueMask[mask]) {
            trueMask[mask] = 1;
            cycle[mask] = tmp;
          }
        }
      }
    }
  }
  memset(dp, 0, sizeof dp);
  REP(i, 0, (1 << n)) {
    if (trueMask[i]) dp[i] = 1;
    for (int subMask = i; subMask; subMask = (subMask - 1) & i) {
      if (dp[subMask] && dp[subMask ^ i]) {
        dp[i] = 1;
        cpnt[i] = subMask;
        break;
      }
    }
  }
  if (!dp[(1 << n) - 1]) {
    printf("No\n");
  } else {
    printf("Yes\n");
    ans.resize(n);
    getAns((1 << n) - 1);
    REP(i, 0, n) { printf("%d %d\n", ans[i].first, ans[i].second); }
  }
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d", &n);
    int ni;
    REP(i, 0, n) {
      scanf("%d", &ni);
      a[i].resize(ni);
      REP(j, 0, ni) { scanf("%d", &a[i][j]); }
    }
    solve();
  }

  return 0;
}
