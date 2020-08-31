#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x))
#define suf_zero(x) __builtin_ffs(x)
#define pre_zero(x) __builtin_clz(x)
#define num_one(x) __builtin_popcount(x)

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
  cerr << *it << " = " << a << " , ";
  err(++it, args...);
}
// usage:
// int a = 4, b = 8, c = 9;
// error(a, b, c);

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

    //      num z(cos(angle), sin(angle));

    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];

      //        roots[(i << 1) + 1] = roots[i] * z;

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

// f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
// SG[]:0~n的SG函数值
// S[]:为x后继状态的集合
const int N = 1000;
const int MAXN = 1000;
int f[N], SG[MAXN], S[MAXN];
void getSG(int n) {
  int i, j;
  memset(SG, 0, sizeof(SG));
  //因为SG[0]始终等于0，所以i从1开始
  for (i = 1; i <= n; i++) {
    //每一次都要将上一状态 的 后继集合 重置
    memset(S, 0, sizeof(S));
    for (j = 0; f[j] <= i && j <= N; j++)
      S[SG[i - f[j]]] = 1;  //将后继状态的SG函数值进行标记
    for (j = 0;; j++)
      if (!S[j]) {  //查询当前后继状态SG值中最小的非零值
        SG[i] = j;
        break;
      }
  }
}