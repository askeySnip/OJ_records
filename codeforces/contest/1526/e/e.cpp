/*
AUTHOR: lz.askey
CREATED: 21.08.2021 17:24:26
LANG: C++14
*/
#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define bit(x, i) (x & (1 << i))
#define in(i, l, r) (l < i && i < r)
#define linr(i, l, r) (l <= i && i <= r)
#define lin(i, l, r) (l <= i && i < r)
#define inr(i, l, r) (l < i && i <= r)
#define gi(a) scanf("%d", &a)
#define gii(a, b) scanf("%d%d", &a, &b)
#define giii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define gs(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define c2i(c) (c - '0')
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
// for debug
#define what_is(x) \
  cerr << "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct
const int MOD = 998244353;
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

  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a
    // 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }

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

// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vi a(n);
  REP(i, 0, n) cin >> a[i];
  vi pos(n + 1);
  REP(i, 0, n) pos[a[i]] = i;
  pos[n] = -1;
  int cnt = 0;
  REP(i, 0, n - 1) {
    if (pos[a[i] + 1] > pos[a[i + 1] + 1]) ++cnt;
  }
  --k;
  k -= cnt;
  if (k < 0) {
    cout << "0\n";
    return 0;
  }
  mod_int ans = 1;
  REP(i, 1, n + 1) {
    ans /= i;
    ans *= (k + i);
  }
  cout << ans.val << "\n";
  return 0;
}
