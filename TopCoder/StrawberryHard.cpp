// BEGIN CUT HERE

// END CUT HERE
#line 5 "StrawberryHard.cpp"
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

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }

  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

 private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}

constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

namespace fft {

typedef double dbl;

struct num {
  dbl x, y;
  num() { x = y = 0; }
  num(dbl x_, dbl y_) : x(x_), y(y_) {}
};

inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) {
  return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline num conj(num a) { return num(a.x, -a.y); }

int base = 1;
vector<num> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = static_cast<dbl>(acosl(-1.0));

void ensure_base(int nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    dbl angle = 2 * PI / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];
      dbl angle_i = angle * (2 * i + 1 - (1 << base));
      roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
    }
    base++;
  }
}

void fft(vector<num>& a, int n = -1) {
  if (n == -1) {
    n = (int)a.size();
  }
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        num z = a[i + j + k] * roots[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

vector<num> fa, fb;

vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
  if (a.empty() || b.empty()) {
    return {};
  }
  int eq = (a.size() == b.size() && a == b);
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if (sz > (int)fa.size()) {
    fa.resize(sz);
  }
  for (int i = 0; i < (int)a.size(); i++) {
    int x = (a[i] % m + m) % m;
    fa[i] = num(x & ((1 << 15) - 1), x >> 15);
  }
  fill(fa.begin() + a.size(), fa.begin() + sz, num{0, 0});
  fft(fa, sz);
  if (sz > (int)fb.size()) {
    fb.resize(sz);
  }
  if (eq) {
    copy(fa.begin(), fa.begin() + sz, fb.begin());
  } else {
    for (int i = 0; i < (int)b.size(); i++) {
      int x = (b[i] % m + m) % m;
      fb[i] = num(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fb.begin() + b.size(), fb.begin() + sz, num{0, 0});
    fft(fb, sz);
  }
  dbl ratio = 0.25 / sz;
  num r2(0, -1);
  num r3(ratio, 0);
  num r4(0, -ratio);
  num r5(0, 1);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    num a1 = (fa[i] + conj(fa[j]));
    num a2 = (fa[i] - conj(fa[j])) * r2;
    num b1 = (fb[i] + conj(fb[j])) * r3;
    num b2 = (fb[i] - conj(fb[j])) * r4;
    if (i != j) {
      num c1 = (fa[j] + conj(fa[i]));
      num c2 = (fa[j] - conj(fa[i])) * r2;
      num d1 = (fb[j] + conj(fb[i])) * r3;
      num d2 = (fb[j] - conj(fb[i])) * r4;
      fa[i] = c1 * d1 + c2 * d2 * r5;
      fb[i] = c1 * d2 + c2 * d1;
    }
    fa[j] = a1 * b1 + a2 * b2 * r5;
    fb[j] = a1 * b2 + a2 * b1;
  }
  fft(fa, sz);
  fft(fb, sz);
  vector<int> res(need);
  for (int i = 0; i < need; i++) {
    int64_t aa = llround(fa[i].x);
    int64_t bb = llround(fb[i].x);
    int64_t cc = llround(fa[i].y);
    res[i] = static_cast<int>((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
  }
  return res;
}

}  // namespace fft

template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value,
                   vector<Modular<T>>>::type
operator*(const vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (min(a.size(), b.size()) < 150) {
    vector<Modular<T>> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int)a.size(); i++) {
      for (int j = 0; j < (int)b.size(); j++) {
        c[i + j] += a[i] * b[j];
      }
    }
    return c;
  }
  vector<int> a_mul(a.size());
  for (int i = 0; i < (int)a.size(); i++) {
    a_mul[i] = static_cast<int>(a[i]);
  }
  vector<int> b_mul(b.size());
  for (int i = 0; i < (int)b.size(); i++) {
    b_mul[i] = static_cast<int>(b[i]);
  }
  vector<int> c_mul = fft::multiply_mod(a_mul, b_mul, T::value);
  vector<Modular<T>> c(c_mul.size());
  for (int i = 0; i < (int)c.size(); i++) {
    c[i] = c_mul[i];
  }
  return c;
}

template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value,
                   vector<Modular<T>>>::type&
operator*=(vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  return a = a * b;
}

// state = seed
// for i = 0 .. 2*k:
//     state = (1103515245 * state + 12345)
//     state = state modulo 2^31
//     A[i] = state modulo Arange
//     state = (1103515245 * state + 12345)
//     state = state modulo 2^31
//     B[i] = state modulo Brange

class StrawberryHard {
 public:
  int competitive(int n, int k, int Arange, int Brange, int seed) {
    vector<Mint> a(2 * k + 1);
    vector<Mint> b(2 * k + 1);
    long long state = seed;
    Mint sum_a = 0;
    Mint sum_b = 0;
    for (int i = 0; i <= 2 * k; i++) {
      state = 1103515245 * state + 12345;
      state %= (1LL << 31);
      a[i] = state % Arange;
      state = 1103515245 * state + 12345;
      state %= (1LL << 31);
      b[i] = state % Brange;
      sum_a += a[i];
      sum_b += b[i];
    }
    Mint inv_sum_a = 1 / sum_a;
    Mint inv_sum_b = 1 / sum_b;
    for (int i = 0; i <= 2 * k; i++) {
      a[i] *= inv_sum_a;
      b[i] *= inv_sum_b;
    }
    vector<Mint> dp(2 * k + 1, 0);
    dp[k] = 1;
    for (int rd = 0; rd < n; rd++) {
      if (rd % 2 == 0) {
        dp *= a;
      } else {
        dp *= b;
      }
      dp.resize(2 * k + 1);
      reverse(dp.begin(), dp.end());
    }
    Mint ans = 0;
    for (int i = 0; i <= 2 * k; i++) {
      ans += dp[i];
    }
    return ans();
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
    int Arg0 = 1;
    int Arg1 = 3;
    int Arg2 = 2;
    int Arg3 = 7;
    int Arg4 = 0;
    int Arg5 = 571428576;
    verify_case(0, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_1() {
    int Arg0 = 6;
    int Arg1 = 3;
    int Arg2 = 3;
    int Arg3 = 3;
    int Arg4 = 740562;
    int Arg5 = 1;
    verify_case(1, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_2() {
    int Arg0 = 7;
    int Arg1 = 3;
    int Arg2 = 3;
    int Arg3 = 3;
    int Arg4 = 740562;
    int Arg5 = 753086426;
    verify_case(2, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4));
  }
  void test_case_3() {
    int Arg0 = 7;
    int Arg1 = 5;
    int Arg2 = 11;
    int Arg3 = 13;
    int Arg4 = 47;
    int Arg5 = 931930680;
    verify_case(3, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  StrawberryHard ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
