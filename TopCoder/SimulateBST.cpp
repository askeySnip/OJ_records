// BEGIN CUT HERE

// END CUT HERE
#line 5 "SimulateBST.cpp"
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

mod_int p10i[500010];
// S(i) = (a * S(i - p) + D(S(i - 1)) + 1) modulo m.
class SimulateBST {
 public:
  void update(map<int, int>& d, int v) {
    if (!d.count(v)) {
      auto it = d.lower_bound(v);
      if (it == d.end()) {
        it--;
        d[v] = it->second + 1;
      } else {
        int dg = it->second;
        if (it == d.begin()) {
          d[v] = dg + 1;
        } else {
          it--;
          d[v] = max(it->second, dg) + 1;
        }
      }
    }
  }
  int checksum(int n, vector<int> Sprefix, int a, int m) {
    vi s = Sprefix;
    s.resize(n);
    int p = Sprefix.size();
    mod_int ans = 0;
    p10i[0] = 1;
    REP(i, 1, n) { p10i[i] = mod_int(1e5).pow(i); }
    map<int, int> d;
    d[s[0]] = 0;
    REP(i, 1, p) {
      int v = s[i];
      update(d, v);
      ans += d[v] * p10i[i];
    }
    REP(i, p, n) {
      s[i] = (1LL * a * s[i - p] + d[s[i - 1]] + 1) % m;
      update(d, s[i]);
      ans += d[s[i]] * p10i[i];
    }
    return ans.val;
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
  string print_array(const vector<T>& V) {
    ostringstream os;
    os << "{ ";
    for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
         ++iter)
      os << '\"' << *iter << "\",";
    os << " }";
    return os.str();
  }
  void verify_case(int Case, const int& Expected, const int& Received) {
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
    int Arg0 = 3;
    int Arr1[] = {10, 20, 30};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 100;
    int Arg4 = 99860;
    verify_case(0, Arg4, checksum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 3;
    int Arr1[] = {10, 10, 10};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 100;
    int Arg4 = 0;
    verify_case(1, Arg4, checksum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 3;
    int Arr1[] = {20, 10, 30};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 100;
    int Arg4 = 99930;
    verify_case(2, Arg4, checksum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 9;
    int Arr1[] = {40, 20, 60, 70, 80, 30, 10, 30, 90};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 0;
    int Arg3 = 100;
    int Arg4 = 461469106;
    verify_case(3, Arg4, checksum(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_4() {
    int Arg0 = 15;
    int Arr1[] = {10, 20, 30};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arg2 = 100;
    int Arg3 = 1000000007;
    int Arg4 = 149719615;
    verify_case(4, Arg4, checksum(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  SimulateBST ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
