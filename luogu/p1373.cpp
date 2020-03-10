/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cassert>
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
const int inf = 1e9;
const int MOD = 1e9 + 7;
struct mod_int {
  int val;

  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;

    if (v >= MOD) v %= MOD;

    val = v;
  }

  static int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }

    return x < 0 ? x + m : x;
  }

  explicit operator int() const { return val; }

  mod_int& operator+=(const mod_int& other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  mod_int& operator-=(const mod_int& other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  static unsigned fast_mod(uint64_t x, unsigned m = MOD) { return x % m; }

  mod_int& operator*=(const mod_int& other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }

  mod_int& operator/=(const mod_int& other) { return *this *= other.inv(); }

  friend mod_int operator+(const mod_int& a, const mod_int& b) {
    return mod_int(a) += b;
  }

  friend mod_int operator-(const mod_int& a, const mod_int& b) {
    return mod_int(a) -= b;
  }

  friend mod_int operator*(const mod_int& a, const mod_int& b) {
    return mod_int(a) *= b;
  }

  friend mod_int operator/(const mod_int& a, const mod_int& b) {
    return mod_int(a) /= b;
  }

  mod_int& operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }

  mod_int operator++(int) {
    mod_int before = *this;
    ++*this;
    return before;
  }

  mod_int& operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }

  mod_int operator--(int) {
    mod_int before = *this;
    --*this;
    return before;
  }

  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }

  bool operator==(const mod_int& other) const { return val == other.val; }

  bool operator!=(const mod_int& other) const { return val != other.val; }

  mod_int inv() const { return mod_inv(val); }

  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;

    while (p > 0) {
      if (p & 1) result *= a;

      a *= a;
      p >>= 1;
    }

    return result;
  }
};

// struct

// data
int n, m, k;
int a[810][810];
mod_int dp[2][810][810][16];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  k++;
  memset(dp, 0, sizeof dp);
  REP(i, 1, n + 1) {
    REP(j, 1, m + 1) scanf("%d", &a[i][j]), dp[0][i][j][a[i][j] % k] = 1;
  }
  REP(i, 1, n + 1) {
    REP(j, 1, m + 1) {
      REP(kk, 0, k) {
        dp[0][i][j][kk] += dp[1][i - 1][j][(kk - a[i][j] + k) % k] +
                           dp[1][i][j - 1][(kk - a[i][j] + k) % k];
        dp[1][i][j][kk] += dp[0][i - 1][j][(kk + a[i][j]) % k] +
                           dp[0][i][j - 1][(kk + a[i][j]) % k];
      }
    }
  }
  mod_int ans = 0;
  REP(i, 1, n + 1) {
    REP(j, 1, m + 1) { ans += dp[1][i][j][0]; }
  }
  printf("%d\n", ans.val);
  return 0;
}
