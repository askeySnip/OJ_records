// BEGIN CUT HERE

// END CUT HERE
#line 5 "DistancePermutation.cpp"
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
const int mod = 1e9 + 7;

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

 private:
  Type value;
};

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}

constexpr int md = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

class DistancePermutation {
 public:
  int solve(vector<int> parent) {
    int n = (int)parent.size() + 1;
    if (n == 1) {
      return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x = parent[i];
      int y = i + 1;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> depth(n);
    vector<int> height(n);
    vector<int> sz(n);
    vector<int> order;
    function<void(int, int)> Dfs = [&](int v, int pr) {
      order.push_back(v);
      height[v] = 0;
      sz[v] = 1;
      for (int u : g[v]) {
        if (u == pr) {
          continue;
        }
        depth[u] = depth[v] + 1;
        Dfs(u, v);
        sz[v] += sz[u];
        height[v] = max(height[v], height[u] + 1);
      }
    };
    vector<Mint> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    auto C = [&](int N, int K) { return fact[N] / (fact[K] * fact[N - K]); };
    Mint ans = n * fact[n];
    for (int r = 0; r < n; r++) {
      depth[r] = 0;
      order.clear();
      Dfs(r, -1);
      vector<int> useless(n, 0);
      for (int s : order) {
        if (s == r) {
          continue;
        }
        if (useless[s]) {
          for (int u : g[s]) {
            if (depth[u] != depth[s] + 1) {
              continue;
            }
            useless[u] = 1;
          }
          continue;
        }
        vector<int> children;
        int ballast = 1;  // node s;
        for (int u : g[s]) {
          if (depth[u] != depth[s] + 1) {
            continue;
          }
          if (height[u] + 1 >= depth[s]) {
            children.push_back(sz[u]);
            for (int uu : g[s]) {
              if (depth[uu] != depth[s] + 1) {
                continue;
              }
              if (uu != u) {
                useless[uu] = 1;
              }
            }
          } else {
            ballast += sz[u];
          }
        }
        if (children.empty()) {
          continue;
        }
        int all = ballast;
        vector<Mint> dp(n + 1, 0);
        dp[ballast] = -1;
        for (int x : children) {
          all += x;
          for (int i = n - x; i >= 0; i--) {
            dp[i + x] += dp[i];
            dp[i] *= -1;
          }
        }
        for (int t = ballast; t < all; t++) {
          if (dp[t]() == 0) {
            continue;
          }
          Mint cur = 0;
          for (int k = 1; k <= t; k++) {
            cur += C(t, k) * fact[n - k] * fact[k];
          }
          ans += cur * dp[t];
        }
      }
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
    if ((Case == -1) || (Case == 4)) test_case_4();
    if ((Case == -1) || (Case == 5)) test_case_5();
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
    int Arr0[] = {0};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 4;
    verify_case(0, Arg1, solve(Arg0));
  }
  void test_case_1() {
    int Arr0[] = {0, 0};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 22;
    verify_case(1, Arg1, solve(Arg0));
  }
  void test_case_2() {
    int Arr0[] = {0, 1};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 22;
    verify_case(2, Arg1, solve(Arg0));
  }
  void test_case_3() {
    int Arr0[] = {0, 0, 0};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 174;
    verify_case(3, Arg1, solve(Arg0));
  }
  void test_case_4() {
    int Arr0[] = {0, 0, 1, 0, 2, 3};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 61008;
    verify_case(4, Arg1, solve(Arg0));
  }
  void test_case_5() {
    int Arr0[] = {};
    vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
    int Arg1 = 0;
    verify_case(5, Arg1, solve(Arg0));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  DistancePermutation ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
