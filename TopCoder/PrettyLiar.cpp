// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrettyLiar.cpp"
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

class PrettyLiar {
 public:
  int n;
  int count(int S, vector<int> kaede, vector<int> kanade) {
    n = kaede.size();
    vector<mod_int> fact(101);
    fact[0] = 1;
    REP(i, 1, 101) fact[i] = fact[i - 1] * i;
    vector<mod_int> coef(n);
    REP(i, 0, n) {
      mod_int a = fact[i + 1] * fact[i];
      mod_int b = fact[n - i - 1] * fact[n - i - 1];
      coef[i] = a * b;
    }
    vector<vector<mod_int>> kaede_subsets(n + 1,
                                          vector<mod_int>(100 * n + 1, 0));
    vector<vector<mod_int>> kanade_subsets(n + 1,
                                           vector<mod_int>(100 * n + 1, 0));
    kaede_subsets[0][0] = 1;
    kanade_subsets[0][0] = 1;
    REP(i, 0, n) {
      for (int sz = n - 1; sz >= 0; sz--) {
        REP(sum, 0, 100 * i + 1) {
          kaede_subsets[sz + 1][sum + kaede[i]] += kaede_subsets[sz][sum];
          kanade_subsets[sz + 1][sum + kanade[i]] += kanade_subsets[sz][sum];
        }
      }
    }
    vector<vector<mod_int>> kaede_psum(n + 1, vector<mod_int>(100 * n + 2, 0));
    REP(i, 0, n + 1) {
      REP(j, 0, 100 * n + 1) {
        kaede_psum[i][j + 1] = kaede_psum[i][j] + kaede_subsets[i][j];
      }
    }
    mod_int ans = 0;
    REP(last, 0, n) {
      int choose = kanade[last];
      vector<vector<mod_int>> kanade_subsets_fixed = kanade_subsets;
      REP(sz, 1, n + 1) {
        REP(sum, 0, 100 * n + 1) {
          if (kanade_subsets_fixed[sz - 1][sum].val) {
            kanade_subsets_fixed[sz][sum + choose] -=
                kanade_subsets_fixed[sz - 1][sum];
          }
        }
      }
      REP(full, 0, n) {
        REP(kanade_score, 0, S) {
          int kaede_score_lo = max(
              0, S - kanade_score - choose);  //[kaede_score_lo, kaede_score_h)
          int kaede_score_hi = min(100 * n, S - kanade_score);
          if (kaede_score_lo > kaede_score_hi) continue;
          if (kanade_score > 100 * n) continue;
          ans += (kaede_psum[full + 1][kaede_score_hi] -
                  kaede_psum[full + 1][kaede_score_lo]) *
                 kanade_subsets_fixed[full][kanade_score] * coef[full];
        }
      }
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
    if ((Case == -1) || (Case == 5)) test_case_5();
    if ((Case == -1) || (Case == 6)) test_case_6();
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
    int Arg0 = 60;
    int Arr1[] = {10, 40};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 30};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 2;
    verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_1() {
    int Arg0 = 100;
    int Arr1[] = {10, 40};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 30};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 4;
    verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_2() {
    int Arg0 = 10;
    int Arr1[] = {10, 40};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {20, 30};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 0;
    verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_3() {
    int Arg0 = 25;
    int Arr1[] = {6, 14};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {7, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 2;
    verify_case(3, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_4() {
    int Arg0 = 178;
    int Arr1[] = {25, 6, 14, 100, 71, 49};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {17, 7, 1, 100, 62, 43};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 240192;
    verify_case(4, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_5() {
    int Arg0 = 1546;
    int Arr1[] = {50, 77, 74, 23, 43, 4,  57, 13, 50, 94, 43, 72, 94,
                  36, 20, 23, 27, 7,  3,  21, 16, 64, 28, 20, 2,  40,
                  92, 93, 17, 94, 43, 17, 1,  87, 58, 67, 43, 22, 99,
                  76, 13, 10, 45, 28, 2,  5,  37, 26, 76, 12};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {40, 93, 80, 23, 20, 71, 23, 14, 43, 45, 38, 20, 61,
                  84, 35, 9,  85, 71, 7,  21, 10, 42, 23, 20, 38, 73,
                  58, 97, 32, 3,  43, 99, 31, 39, 33, 73, 81, 3,  9,
                  73, 17, 68, 50, 27, 25, 86, 22, 47, 64, 8};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 949234178;
    verify_case(5, Arg3, count(Arg0, Arg1, Arg2));
  }
  void test_case_6() {
    int Arg0 = 4;
    int Arr1[] = {1, 1, 1, 1};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 1, 1, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 576;
    verify_case(6, Arg3, count(Arg0, Arg1, Arg2));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  PrettyLiar ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
