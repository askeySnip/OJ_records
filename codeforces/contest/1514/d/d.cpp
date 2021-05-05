/*
AUTHOR: lz.askey
CREATED: 20.04.2021 21:45:30
LANG: C++11
*/
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <chrono>
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
#include <random>
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
const int N = 300010;
// data
// vi v[N];
// int a[N], tree[4 * N];

// int cnt(int l, int r, int x) {
//   return upper_bound(all(v[x]), r) - lower_bound(all(v[x]), l);
// }

// void build(int p, int l, int r) {
//   if (l == r) {
//     tree[p] = a[l];
//     return;
//   }
//   int mid = (l + r) / 2;
//   build(p * 2, l, mid);
//   build(p * 2 + 1, mid + 1, r);
//   tree[p] = cnt(l, r, tree[p * 2]) > cnt(l, r, tree[p * 2 + 1])
//                 ? tree[p * 2]
//                 : tree[p * 2 + 1];
// }

// int query(int p, int st, int en, int l, int r) {
//   if (st > r || en < l || l > r) return 0;
//   if (st >= l && en <= r) return cnt(l, r, tree[p]);
//   int mid = (st + en) / 2;
//   return max(query(p * 2, st, mid, l, r), query(p * 2 + 1, mid + 1, en, l,
//   r));
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n, q;
//   cin >> n >> q;
//   REP(i, 1, n + 1) cin >> a[i], v[a[i]].push_back(i);
//   build(1, 1, n);
//   int l, r;
//   REP(i, 0, q) {
//     cin >> l >> r;
//     cout << max(1, 2 * query(1, 1, n, l, r) - (r - l + 1)) << "\n";
//   }
//   return 0;
// }

vi v[N];
int a[N];

int cnt(int l, int r, int x) {
  return upper_bound(all(v[x]), r) - lower_bound(all(v[x]), l);
}

int main() {
  int n, q;
  gii(n, q);
  REP(i, 1, n + 1) cin >> a[i], v[a[i]].push_back(i);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int l, r;
  REP(i, 0, q) {
    gii(l, r);
    int ans = 1;
    REP(j, 0, 40) {
      int c = a[uniform_int_distribution<int>(l, r)(rng)];
      int f = upper_bound(all(v[c]), r) - lower_bound(all(v[c]), l);
      ans = max(ans, 2 * f - (r - l + 1));
    }
    cout << ans << "\n";
  }
}
