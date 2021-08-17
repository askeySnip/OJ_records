/*
AUTHOR: lz.askey
CREATED: 31.07.2021 20:03:32
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
typedef vector<pair<int, int>> vii;
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
vector<int> t, ps;

// void push(int v) {
//   if (v * 2 + 1 < int(ps.size())) {
//     ps[v * 2] += ps[v];
//     ps[v * 2 + 1] += ps[v];
//   }
//   t[v] += ps[v];
//   ps[v] = 0;
// }

// void upd(int v, int l, int r, int L, int R, int val) {
//   push(v);
//   if (L >= R) return;
//   if (l == L && r == R) {
//     ps[v] += val;
//     push(v);
//     return;
//   }
//   int m = (l + r) / 2;
//   upd(v * 2, l, m, L, min(m, R), val);
//   upd(v * 2 + 1, m, r, max(m, L), R, val);
//   t[v] = min(t[v * 2], t[v * 2 + 1]);
// }

// int get() { return t[1] + ps[1]; }
void push(int v) {
  t[v * 2] += ps[v];
  ps[v * 2] += ps[v];
  t[v * 2 + 1] += ps[v];
  ps[v * 2 + 1] += ps[v];
  ps[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val) {
  if (l > r) return;
  if (l == tl && r == tr) {
    t[v] += val;
    ps[v] += val;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
int get() { return t[1]; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> a;
  REP(i, 0, n) {
    int l, r, w;
    cin >> l >> r >> w;
    --l, r -= 2;
    a.emplace_back(w, l, r);
  }
  --m;
  sort(all(a), [](tuple<int, int, int>& x, tuple<int, int, int>& y) {
    return get<0>(x) < get<0>(y);
  });
  t.resize(4 * m), ps.resize(4 * m);
  --m;
  int ans = inf;
  int j = 0;
  REP(i, 0, n) {
    while (j < n && get() == 0) {
      upd(1, 0, m, get<1>(a[j]), get<2>(a[j]), 1);
      ++j;
    }
    if (get() == 0) break;
    ans = min(ans, get<0>(a[j - 1]) - get<0>(a[i]));
    // error(i, j, ans);
    upd(1, 0, m, get<1>(a[i]), get<2>(a[i]), -1);
    // error(get());
  }
  cout << ans << "\n";
  return 0;
}
