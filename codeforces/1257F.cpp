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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n;
int a[110];
int cnt[110];
int tmpcnt[110];
const int seed = 13;

unsigned long long getHash() {
  unsigned long long ret = 0;
  REP(i, 0, n) { ret = ret * seed + cnt[i]; }
  return ret;
}

void solve() {
  map<ull, int> mem;
  REP(i, 0, 1 << 15) {
    REP(j, 0, n) {
      int t = a[j] & ((1 << 15) - 1);
      cnt[j] = __builtin_popcount(t ^ i);
    }
    ull h = getHash();
    mem[h] = i;
  }
  REP(i, 0, 1 << 15) {
    REP(j, 0, n) {
      int t = (a[j] >> 15);
      tmpcnt[j] = __builtin_popcount(t ^ i);
    }
    REP(j, 0, 30) {
      bool f = true;
      REP(k, 0, n) {
        cnt[k] = j - tmpcnt[k];
        if (cnt[k] < 0) {
          f = false;
          break;
        }
      }
      if (!f) continue;
      ull h = getHash();
      if (mem.find(h) != mem.end()) {
        int ans = (i << 15) + mem[h];
        printf("%d\n", ans);
        int x = __builtin_popcount(ans ^ a[0]);
        REP(j, 0, n) {
          if (x != __builtin_popcount(ans ^ a[j])) {
            printf("failed\n");
            break;
          }
        }
        return;
      }
    }
  }
  printf("-1\n");
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    solve();
  }

  return 0;
}
