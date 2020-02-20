// BEGIN CUT HERE

// END CUT HERE
#line 5 "Strawberry.cpp"
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

class Strawberry {
 public:
  int n, k;
  mod_int sa, sb;
  vector<mod_int> pa, pb;
  mod_int mem[110][310];
  int competitive(int _n, int _k, vector<int> A, vector<int> B) {
    n = _n, k = _k;
    sa = sb = 0;
    pa.clear(), pb.clear();
    REP(i, 0, A.size()) sa += A[i];
    REP(i, 0, B.size()) sb += B[i];
    REP(i, 0, A.size()) pa.push_back(mod_int(A[i]) / sa);
    REP(i, 0, B.size()) pb.push_back(mod_int(B[i]) / sb);
    REP(i, 0, 110) REP(j, 0, 310) mem[i][j] = -1;
    dp(0, k);
    return (int)mem[0][k];
  }
  mod_int dp(int round, int dif) {  // dif = a - b;
    if (dif > 2 * k || dif < 0) return 0;
    if (round == n) return 1;
    if (mem[round][dif] != -1) return mem[round][dif];
    mod_int ret = 0;
    if (round % 2 == 0) {
      REP(i, 0, 2 * k + 1) { ret += dp(round + 1, dif + i) * pa[i]; }
    } else {
      REP(i, 0, 2 * k + 1) { ret += dp(round + 1, dif - i) * pb[i]; }
    }
    return mem[round][dif] = ret;
  }
  // BEGIN CUT HERE
 public:
  void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3();
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
    int Arg0 = 1;
    int Arg1 = 3;
    int Arr2[] = {1, 1, 1, 1, 1, 1, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {1, 1, 1, 1, 1, 1, 1};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arg4 = 571428576;
    verify_case(0, Arg4, competitive(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_1() {
    int Arg0 = 6;
    int Arg1 = 3;
    int Arr2[] = {4, 7, 0, 0, 0, 0, 0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {4, 2, 0, 0, 0, 0, 0};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arg4 = 1;
    verify_case(1, Arg4, competitive(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_2() {
    int Arg0 = 7;
    int Arg1 = 3;
    int Arr2[] = {4, 7, 0, 0, 0, 0, 0};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {4, 2, 0, 0, 0, 0, 0};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arg4 = 969874055;
    verify_case(2, Arg4, competitive(Arg0, Arg1, Arg2, Arg3));
  }
  void test_case_3() {
    int Arg0 = 50;
    int Arg1 = 5;
    int Arr2[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arr3[] = {200, 101, 202, 203, 204, 205, 206, 207, 208, 209, 210};
    vector<int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
    int Arg4 = 440607283;
    verify_case(3, Arg4, competitive(Arg0, Arg1, Arg2, Arg3));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  Strawberry ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
