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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct
struct mat {
  int row, col;
  int a[32][32];
  mat() { memset(a, 0, sizeof a); }

  mat operator*(const mat& x) const {
    mat ans = mat();
    ans.row = row;
    ans.col = col;
    REP(i, 0, row) {
      REP(j, 0, col) {
        REP(kk, 0, col) {
          ans.a[i][j] += (1LL * a[i][kk] * x.a[kk][j]) % mod;
          ans.a[i][j] %= mod;
        }
      }
    }
    return ans;
  }

  mat operator^(ll n) const {
    mat ans = mat();
    ans.row = row, ans.col = col;
    REP(i, 0, row) ans.a[i][i] = 1;
    mat base = *this;
    for (; n; n >>= 1, base = base * base) {
      if (n & 1) ans = ans * base;
    }
    return ans;
  }
};

// data
ll n;
int m, k;

int main() {
  scanf("%lld%d%d", &n, &m, &k);
  mat b = mat();
  b.row = b.col = (1 << m);
  REP(i, 0, (1 << m)) {
    if (__builtin_popcount(i) > k) continue;
    b.a[i >> 1][i] = 1;
    int j = (i >> 1) | (1 << (m - 1));
    if (__builtin_popcount(j) > k) continue;
    b.a[j][i] = 1;
  }
  mat c = (b ^ n);
  int ans = 0;
  REP(i, 0, 1 << m) { ans = (ans + c.a[i][i]) % mod; }
  printf("%d\n", ans);
  return 0;
}
