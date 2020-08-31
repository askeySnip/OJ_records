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
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
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
  cerr << *it << " = " << a << " , ";
  err(++it, args...);
}
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct
class UnionFind {
 private:
  vi p, rank, sz;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        sz[x] += sz[y];
      } else {
        sz[y] += sz[x];
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

// data
int n, m;
int l[300010], r[300010], a[60], b[60];
int cnt[300010];
int A[300010];
int rv[300010];

int add(int x, int y) { return ((x + y) % mod + mod) % mod; }

int mul(int x, int y) { return (x * 1ll * y) % mod; }

int binpow(int x, int y) {
  int z = 1;
  while (y > 0) {
    if (y % 2 == 1) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}

int inv(int x) { return binpow(x, mod - 2); }

int C(int n, int k) {
  if (k > n || n < 0 || k < 0) return 0;
  return mul(A[n], mul(rv[n - k], rv[k]));
}

int main() {
  getII(n, m);

  REP(i, 0, n) { getII(l[i], r[i]); }
  REP(i, 0, m) { getII(a[i], b[i]); }
  REP(i, 0, n) {
    cnt[l[i]]++;
    cnt[r[i] + 1]--;
  }

  REP(i, 0, n + 1) cnt[i + 1] += cnt[i];
  A[0] = 1;
  REP(i, 1, n + 1) A[i] = mul(A[i - 1], i);
  REP(i, 0, n + 1) rv[i] = inv(A[i]);

  vector<vi> p(2 * m + 1, vi(n + 1));
  REP(i, 1, n + 1) {
    REP(j, 0, 2 * m + 1) { p[j][i] = add(p[j][i - 1], C(cnt[i] - j, i - j)); }
  }
  int ans = 0;
  REP(mask, 0, (1 << m)) {
    int sign = 1;
    set<int> used;
    REP(i, 0, m) {
      if (bit(mask, i)) {
        sign = mul(sign, mod - 1);
        used.insert(a[i] - 1);
        used.insert(b[i] - 1);
      }
    }
    int L = 1, R = n;
    for (auto x : used) {
      L = max(L, l[x]);
      R = min(R, r[x]);
    }
    if (R < L) continue;
    ans = add(ans, mul(sign, add(p[used.size()][R], -p[used.size()][L - 1])));
  }
  printf("%d\n", ans);
  return 0;
}
