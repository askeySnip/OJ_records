// BEGIN CUT HERE

// END CUT HERE
#line 5 "LollipopHoney.cpp"
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
typedef vector<pair<int, int>> vii;
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

class LollipopHoney {
 public:
  vector<int> count(int K, vector<int> flavor, vector<int> deliciousness) {
    vector<mod_int> fact(51);
    fact[0] = 1;
    REP(i, 1, 51) fact[i] = fact[i - 1] * i;
    auto C = [&](int n, int k) { return fact[n] / fact[k] / fact[n - k]; };
    vii p(flavor.size());
    REP(i, 0, flavor.size()) p[i] = ii(deliciousness[i], flavor[i]);
    sort(p.begin(), p.end(), greater<ii>());
    map<int, map<int, int>> group;
    REP(i, 0, p.size()) {
      if (group.find(p[i].first) == group.end()) group[p[i].first] = {};
      group[p[i].first][p[i].second]++;
    }
    int delic = 0;
    mod_int ways = 1;
    int k = 2 * K;
    map<int, int> fcnt;
    for (auto f : flavor) fcnt[f] = 0;
    for (auto it = group.rbegin(); it != group.rend(); it++) {
      int d = it->first;
      int cnt = 0;
      for (auto i : it->second) {
        cnt += min(K - fcnt[i.first], i.second);
      }
      delic += min(cnt, k) * d;
      if (cnt <= k) {
        for (auto i : it->second) {
          ways *= C(i.second, min(K - fcnt[i.first], i.second));
          fcnt[i.first] += min(K - fcnt[i.first], i.second);
        }
      } else {
        vector<mod_int> dp(k + 1, 0);
        dp[0] = 1;
        for (auto ii : it->second) {
          vector<mod_int> dp1(k + 1, 0);
          int mf = min(K - fcnt[ii.first], ii.second);
          REP(i, 0, k + 1) {
            REP(j, 0, mf + 1) {
              if (i + j <= k) {
                dp1[i + j] += dp[i] * C(ii.second, j);
              }
            }
          }
          dp = dp1;
        }
        ways *= dp[k];
      }
      k -= min(k, cnt);
      if (k == 0) break;
    }
    if (k) return {};
    return {delic, ways.val};
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
  void verify_case(int Case, const vector<int>& Expected,
                   const vector<int>& Received) {
    cerr << "Test Case #" << Case << "...";
    if (Expected == Received)
      cerr << "PASSED" << endl;
    else {
      cerr << "FAILED" << endl;
      cerr << "\tExpected: " << print_array(Expected) << endl;
      cerr << "\tReceived: " << print_array(Received) << endl;
    }
  }
  void test_case_0() {
    int Arg0 = 1;
    int Arr1[] = {1, 1, 2, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {10, 20, 30, 40};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {60, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {1, 1, 1, 2, 2, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {10, 10, 10, 20, 20, 20};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {60, 9};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 2;
    int Arr1[] = {1, 1, 1, 1, 1, 2};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {10, 20, 30, 40, 50, 60};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 3;
    int Arr1[] = {48, 33, 22, 9, 37, 44, 5, 49, 24, 14, 45, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {9, 1, 7, 10, 7, 10, 5, 1, 3, 3, 4, 5};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {48, 2};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(3, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 10;
    int Arr1[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
                  29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {20, 846527861};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    verify_case(4, Arg3, count(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  LollipopHoney ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
