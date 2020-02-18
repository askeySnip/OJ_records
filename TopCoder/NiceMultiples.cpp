// BEGIN CUT HERE

// END CUT HERE
#line 5 "NiceMultiples.cpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
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

  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  mod_int &operator-=(const mod_int &other) {
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

  mod_int &operator*=(const mod_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }

  mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }

  friend mod_int operator+(const mod_int &a, const mod_int &b) {
    return mod_int(a) += b;
  }

  friend mod_int operator-(const mod_int &a, const mod_int &b) {
    return mod_int(a) -= b;
  }

  friend mod_int operator*(const mod_int &a, const mod_int &b) {
    return mod_int(a) *= b;
  }

  friend mod_int operator/(const mod_int &a, const mod_int &b) {
    return mod_int(a) /= b;
  }

  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }

  mod_int operator++(int) {
    mod_int before = *this;
    ++*this;
    return before;
  }

  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }

  mod_int operator--(int) {
    mod_int before = *this;
    --*this;
    return before;
  }

  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }

  bool operator==(const mod_int &other) const { return val == other.val; }

  bool operator!=(const mod_int &other) const { return val != other.val; }

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

mod_int mem[3][50][200005];
class NiceMultiples {
 public:
  vi pr;
  ll m, u, b;
  int count(long long M, long long U, int B) {
    m = M, u = U, b = B;
    if (M % B == 0) return 0;
    if (U / M <= 5000000) {
      int ans = 0;
      for (ll i = M; i <= U; i += M) {
        if (check(i, B)) ans++;
      }
      return ans;
    }
    pr.clear();
    ll tu = U;
    while (tu) {
      pr.push_back(tu % B);
      tu /= B;
    }
    REP(i, 0, 3) {
      REP(j, 0, pr.size() + 1) {
        REP(k, 0, M + 3) { mem[i][j][k] = -1; }
      }
    }
    mod_int ans = 0;
    int n = pr.size();
    ans += dp(0, n - 1, 0);
    for (int i = 1; i < pr.back(); i++) ans += dp(1, n - 1, i % m);
    ans += dp(2, n - 1, pr.back() % m);
    return (int)ans;
  }
  mod_int dp(int state, int left, int r) {
    if (left == 0) {
      if (!r && state) return 1;
      return 0;
    }
    if (mem[state][left][r] != -1) return mem[state][left][r];
    mod_int ret = 0;
    if (state == 0) ret += dp(0, left - 1, (r * b) % m);
    if (state == 2) {
      for (int i = 1; i < pr[left - 1]; i++)
        ret += dp(1, left - 1, (r * b + i) % m);
      if (pr[left - 1]) ret += dp(2, left - 1, (r * b + pr[left - 1]) % m);
    } else {
      for (int i = 1; i < b; i++) ret += dp(1, left - 1, (r * b + i) % m);
    }
    return mem[state][left][r] = ret;
  }
  bool check(ll n, int b) {
    while (n) {
      if (n % b == 0) return false;
      n /= b;
    }
    return true;
  }

  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
    if ((Case == -1) || (Case == 4)) test_case_4();
  }

 private:
  template <typename T>
  string print_array(const vector<T> &V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int &Expected, const int &Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: \"" << Expected << '\"' << endl;
      cerr << "\tReceived: \"" << Received << '\"' << endl;
    }
  }
  void test_case_0() {
    long long Arg0 = 1LL;
    long long Arg1 = 100LL;
    int Arg2 = 2;
    int Arg3 = 6;
    verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    long long Arg0 = 6LL;
    long long Arg1 = 123456789LL;
    int Arg2 = 3;
    int Arg3 = 0;
    verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    long long Arg0 = 2LL;
    long long Arg1 = 117LL;
    int Arg2 = 10;
    int Arg3 = 43;
    verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    long long Arg0 = 3333333333LL;
    long long Arg1 = 9999999999LL;
    int Arg2 = 10;
    int Arg3 = 3;
    verify_case(3, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    long long Arg0 = 1LL;
    long long Arg1 = 100000000000LL;
    int Arg2 = 10;
    int Arg3 = 303691814;
    verify_case(4, Arg3, count(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  NiceMultiples ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
