/*
AUTHOR: lz.askey
CREATED: 17.08.2021 20:07:23
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
#define in(i, l, r) (l < i && i < r)
#define linr(i, l, r) (l <= i && i <= r)
#define lin(i, l, r) (l <= i && i < r)
#define inr(i, l, r) (l < i && i <= r)
#define gi(a) scanf("%d", &a)
#define gii(a, b) scanf("%d%d", &a, &b)
#define giii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define gs(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define c2i(c) (c - '0')
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
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
const int maxn = 1e5 + 10;
int n, m;
int l[maxn], r[maxn];

int dp(vi& b, int sum) {
  vi ps(sum + 1, 1), nxt(sum + 1), nxt_ps(sum + 1);
  auto calc = [&](int low, int high) {
    --low;
    int ans = ps[high];
    if (low >= 0) ans -= ps[low];
    ans = (ans + mod) % mod;
    return ans;
  };
  REP(i, 0, n) {
    REP(j, 0, sum + 1) nxt[j] = calc(j - b[i], j);
    nxt_ps[0] = nxt[0];
    REP(j, 1, sum + 1) nxt_ps[j] = (nxt_ps[j - 1] + nxt[j]) % mod;
    swap(ps, nxt_ps);
  }
  return ps[sum];
}

int func_f(int k) {
  auto nxt_divide_k = [](int x, int y) {
    if (x % y == 0) return x;
    return x + y - (x % y);
  };
  vi bound(n);
  int t = m;
  REP(i, 0, n) {
    int x = nxt_divide_k(l[i], k);
    if (x > r[i]) return 0;
    bound[i] = (r[i] - x) / k;
    t -= x;
  }
  if (t < 0) return 0;
  t /= k;
  return dp(bound, t);
}

// f(i) -- number of states where all numbers divide i
// d(i) -- number of states where gcd = d
// d(i) = f(i) - (d(2i) + d(3i) + ...)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  REP(i, 0, n) cin >> l[i] >> r[i];
  vi f(m + 1, 0);
  REP(i, 1, m + 1) f[i] = func_f(i);
  vi d(m + 1);
  for (int i = m; i > 0; i--) {
    d[i] = f[i];
    for (int j = 2; j * i <= m; j++) {
      d[i] -= d[j * i];
      d[i] = (d[i] + mod) % mod;
    }
  }
  cout << d[1] << '\n';
  return 0;
}
