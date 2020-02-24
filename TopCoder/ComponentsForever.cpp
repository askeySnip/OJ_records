// BEGIN CUT HERE

// END CUT HERE
#line 5 "ComponentsForever.cpp"
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

class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

struct point {
  int x, y, id;
  bool operator<(const point& tmp) const {
    return x == tmp.x ? y < tmp.y : x < tmp.x;
  }
};
ii ft[78000];
void update(int p, ii val) {
  p++;
  for (; p; p -= p & (-p)) {
    ft[p] = min(ft[p], val);
  }
}
int query(int p) {
  p++;
  ii res = ii(inf, -1);
  for (; p < 78000; p += p & (-p)) {
    res = min(res, ft[p]);
  }
  return res.second;
}

int xx[78000], yy[78000], A[78000];
point p[78000];
ii lsh[78000];
int n;
priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
int dst(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
void add(int a, int b, int v) { pq.push(make_pair(v, ii(a, b))); }
void manhattan() {
  while (!pq.empty()) pq.pop();
  REP(dir, 0, 4) {
    REP(i, 0, 78000) ft[i] = ii(inf, -1);
    if (dir == 1 || dir == 3) {
      REP(i, 0, n) swap(p[i].x, p[i].y);
    } else if (dir == 2) {
      REP(i, 0, n) p[i].x = -p[i].x;
    }
    sort(p, p + n);
    REP(i, 0, n) lsh[i] = ii(p[i].y - p[i].x, i);
    sort(lsh, lsh + n);
    REP(i, 0, n) A[lsh[i].second] = i;
    for (int i = n - 1; i >= 0; i--) {
      int pos = query(A[i]);
      if (pos != -1) add(p[i].id, p[pos].id, dst(p[i], p[pos]));
      update(A[i], ii(p[i].x + p[i].y, i));
    }
  }
}
mod_int cacl(mod_int a, mod_int b, mod_int L, mod_int R) {
  a = max(a.val, L.val);
  b = min(b.val, R.val);
  if (b.val < a.val) return 0;
  mod_int ans = b * (b + 1) / 2 - a * (a - 1) / 2 - L * (b - a + 1);
  return ans;
}
mod_int solve(int nn, int Llo, int Rhi) {
  n = nn;
  manhattan();
  mod_int components = n;
  UnionFind uf(n + 1);
  mod_int ans = 0;
  int prel = 1;
  while (!pq.empty()) {
    int u = pq.top().second.first, v = pq.top().second.second,
        w = pq.top().first;
    pq.pop();
    if (!uf.isSameSet(u, v)) {
      uf.unionSet(u, v);
      ans += components * cacl(prel, w - 1, Llo, Rhi);
      components--;
      prel = w;
    }
  }
  ans += components * cacl(prel, Rhi, Llo, Rhi);
  return ans;
}

class ComponentsForever {
 public:
  // for i = 0 .. len(Xprefix)-1:
  //     X[i] = Xprefix[i]
  //     Y[i] = Yprefix[i]

  // state = seed

  // for i = len(Xprefix) .. n-1:
  //     state = (1103515245 * state + 12345)
  //     X[i] = state modulo Xrange
  //     state = state modulo 2^31
  //     state = (1103515245 * state + 12345)
  //     Y[i] = state modulo Yrange
  //     state = state modulo 2^31
  int countComponents(int _n, vector<int> Xprefix, vector<int> Yprefix,
                      int seed, int Xrange, int Yrange, int Llo, int Rhi) {
    REP(i, 0, Xprefix.size()) xx[i] = Xprefix[i], yy[i] = Yprefix[i];
    ll state = seed;
    REP(i, Xprefix.size(), _n) {
      state = (1103515245 * state + 12345);
      xx[i] = state % Xrange;
      state = state % (1 << 31);
      state = (1103515245 * state + 12345);
      yy[i] = state % Yrange;
      state = state % (1 << 31);
    }
    int cnt = 0;
    REP(i, 0, _n) {
      if ((xx[i] + yy[i]) % 2 == 0) {
        p[cnt].x = (xx[i] + yy[i]) / 2;
        p[cnt].y = (xx[i] - yy[i]) / 2;
        p[cnt].id = cnt;
        cnt++;
      }
    }
    mod_int ans = 0;
    if (cnt) ans = solve(cnt, Llo, Rhi);
    cnt = 0;
    REP(i, 0, _n) {
      if ((xx[i] + yy[i]) % 2) {
        xx[i]--;
        p[cnt].x = (xx[i] + yy[i]) / 2;
        p[cnt].y = (xx[i] - yy[i]) / 2;
        p[cnt].id = cnt;
        cnt++;
      }
    }
    if (cnt) ans += solve(cnt, Llo, Rhi);
    ans /= cacl(Llo, Rhi, Llo, Rhi);
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
    int Arg0 = 2;
    int Arr1[] = {1, 4};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    int Arg4 = 1;
    int Arg5 = 1;
    int Arg6 = 1;
    int Arg7 = 5;
    int Arg8 = 2;
    verify_case(
        0, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }
  void test_case_1() {
    int Arg0 = 2;
    int Arr1[] = {1, 3};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {1, 3};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    int Arg4 = 1;
    int Arg5 = 1;
    int Arg6 = 1;
    int Arg7 = 5;
    int Arg8 = 1;
    verify_case(
        1, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }
  void test_case_2() {
    int Arg0 = 2;
    int Arr1[] = {5, 21232};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {6, 123};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1;
    int Arg4 = 1;
    int Arg5 = 1;
    int Arg6 = 1;
    int Arg7 = 5132;
    int Arg8 = 2;
    verify_case(
        2, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }
  void test_case_3() {
    int Arg0 = 18;
    int Arr1[] = {16, 21, 33, 46, 10};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {22, 25, 46, 18, 8};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1253;
    int Arg4 = 47;
    int Arg5 = 31;
    int Arg6 = 12;
    int Arg7 = 86;
    int Arg8 = 394234239;
    verify_case(
        3, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }
  void test_case_4() {
    int Arg0 = 9;
    int Arr1[] = {28, 33, 6, 14, 20, 35, 49, 15, 46};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {48, 32, 11, 28, 1, 22, 24, 41, 1};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 1522;
    int Arg4 = 9;
    int Arg5 = 35;
    int Arg6 = 18;
    int Arg7 = 55;
    int Arg8 = 512091044;
    verify_case(
        4, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }
  void test_case_5() {
    int Arg0 = 70874;
    int Arr1[] = {};
    vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
    int Arr2[] = {};
    vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
    int Arg3 = 477403840;
    int Arg4 = 153268855;
    int Arg5 = 153409203;
    int Arg6 = 523210;
    int Arg7 = 465494481;
    int Arg8 = 248460139;
    verify_case(
        5, Arg8,
        countComponents(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7));
  }

  // END CUT HERE
};

// BEGIN CUT HERE
int main() {
  ComponentsForever ___test;
  ___test.run_test(-1);
  system("pause");
}
// END CUT HERE
