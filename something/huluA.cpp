/*
ID: leezhen
TASK: practice
LANG: C++11
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

  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return x % m;
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
  int n;
  gi(n);
  vi a(n);
  REP(i, 0, n) gi(a[i]);
  map<int, int> cnt;
  REP(i, 0, n) ++cnt[a[i]];
  vector<mod_int> A(n+1);
  A[0] = 1;
  REP(i, 1, n+1) A[i] = A[i-1] * i;
  // mod_int ans = A[n];
  // for(auto it : cnt) {
  //   ans /= A[it.second];
  // }
  mod_int ans = 0;
  int s = 0, pre = 0;
  for(auto it : cnt) {
    s += it.second;
  }
  vi nums;
  for(auto it : cnt) {
    nums.push_back(it.second);
  }
  REP(i, 0, nums.size()) {
    REP(j, 0, nums[i]) {
      mod_int tmp = A[pre] * A[s-pre-1];
      REP(k, 0 , i) {
        tmp /= A[nums[i]];
      }
    }
    pre += nums[i];
  }
  printf("%d\n", ans.val);
  return 0;
}
