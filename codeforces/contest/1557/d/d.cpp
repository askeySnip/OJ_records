/*
AUTHOR: lz.askey
CREATED: 11.08.2021 16:12:47
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
const ii NIL = {0, -1};
struct segment_tree {
  int n;
  vii tree, lazy;
  segment_tree(int n) : n(n) { tree = lazy = vii(n << 2, NIL); }
  void push_down(int idx, int start, int end) {
    if (lazy[idx] == NIL) return;
    tree[idx] = max(tree[idx], lazy[idx]);
    if (start != end) {
      lazy[idx << 1] = max(lazy[idx << 1], lazy[idx]);
      lazy[idx << 1 | 1] = max(lazy[idx << 1 | 1], lazy[idx]);
    }
    lazy[idx] = NIL;
  }

  void update(int idx, int start, int end, int l, int r, ii p) {
    push_down(idx, start, end);
    if (r < start || l > end) return;
    if (l <= start && r >= end) {
      lazy[idx] = max(lazy[idx], p);
      push_down(idx, start, end);
      return;
    }
    update(idx << 1, start, (start + end) >> 1, l, r, p);
    update(idx << 1 | 1, ((start + end) >> 1) + 1, end, l, r, p);
    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
  }
  ii query(int idx, int start, int end, int l, int r) {
    push_down(idx, start, end);
    if (r < start || l > end) return NIL;
    if (l <= start && end <= r) return tree[idx];
    return max(query(idx << 1, start, (start + end) / 2, l, r),
               query(idx << 1 | 1, (start + end) / 2 + 1, end, l, r));
  }
  void update(int l, int r, ii p) { return update(1, 1, n, l, r, p); }
  ii query(int l, int r) { return query(1, 1, n, l, r); }
};

// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vii> v(n);
  vi id;
  REP(j, 0, m) {
    int i, l, r;
    cin >> i >> l >> r;
    id.push_back(l);
    id.push_back(r);
    v[i - 1].emplace_back(l, r);
  }
  sort(all(id));
  id.erase(unique(all(id)), id.end());
  REP(i, 0, n) {
    for (auto& it : v[i]) {
      it.first = upper_bound(all(id), it.first) - id.begin();
      it.second = upper_bound(all(id), it.second) - id.begin();
    }
  }
  segment_tree seg(id.size());
  vi prv(n, -1);
  REP(i, 0, n) {
    ii mx = NIL;
    for (auto& it : v[i]) {
      mx = max(mx, seg.query(it.first, it.second));
    }
    prv[i] = mx.second;
    mx.first++;
    mx.second = i;
    for (auto& it : v[i]) seg.update(it.first, it.second, mx);
  }
  ii p = seg.query(1, id.size());
  vi vis(n, 0);
  int cur = p.second;
  while (cur != -1) {
    vis[cur] = true;
    cur = prv[cur];
  }
  cout << n - p.first << '\n';
  REP(i, 0, n) if (!vis[i]) cout << i + 1 << " ";
  cout << '\n';
  return 0;
}
