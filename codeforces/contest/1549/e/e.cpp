/*
AUTHOR: lz.askey
CREATED: 02.08.2021 23:55:11
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
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data

int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1ll * x * r % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return r;
}

// f(x) = sum_{i=1}^{n}C(3i, x)
// C(n+1, k+1) = C(n, k) + C(n, k+1);
// C(n+3, k+3) = C(n, k) + 3C(n, k+1) + 3C(n, k+2) + C(n, k+3)
// f(x) = C(3n+3, x+3) - 3*(f(x+1) + f(x+2))

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  const int N = 3 * (n + 1);
  vi fac(N + 1), ifac(N + 1);
  fac[0] = 1;
  REP(i, 1, N + 1) fac[i] = (1ll * fac[i - 1] * i) % mod;
  ifac[N] = powMod(fac[N], mod - 2);
  for (int i = N; i > 0; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  auto C = [&](int i) {
    return (1ll * fac[N] * ifac[N - i] % mod) * ifac[i] % mod;
  };
  vi ans(N);
  for (int i = 3 * n; i >= 1; i--) {
    int tmp = 1ll * (ans[i + 1] + ans[i + 2]) * 3 % mod;
    tmp = C(i + 3) - tmp;
    if (tmp < 0) tmp += mod;
    ans[i] = tmp;
  }
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
  return 0;
}
