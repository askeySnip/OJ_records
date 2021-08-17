/*
AUTHOR: lz.askey
CREATED: 05.08.2021 21:26:57
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  set<ii> l, r;
  l.insert({0, 0});
  r.insert({0, 0});
  int p = 0;
  vi pr(n + 1, -1), pr2(n + 1, -1);
  REP(i, 0, n) {
    int k;
    cin >> k;
    int a = sz(l), b = sz(r);
    if (a) r.insert({p, i});
    if (b) l.insert({p, i});
    int l1, r1;
    cin >> l1 >> r1;
    if (k < l1 || k > r1) l.clear();
    int l2, r2;
    cin >> l2 >> r2;
    if (k < l2 || k > r2) r.clear();
    while (!l.empty() && (*l.begin()).first < l2) l.erase(l.begin());
    while (!l.empty() && (*l.rbegin()).first > r2) l.erase(*l.rbegin());
    while (!r.empty() && (*r.begin()).first < l1) r.erase(r.begin());
    while (!r.empty() && (*r.rbegin()).first > r1) r.erase(*r.rbegin());
    p = k;
    if (l.empty() && r.empty()) {
      cout << "No\n";
      return 0;
    }
    if (!l.empty()) {
      pr[i + 1] = (*l.begin()).second;
    }
    if (!r.empty()) {
      pr2[i + 1] = (*r.begin()).second;
    }
  }
  int t = 0;
  if (sz(r)) t = 1;
  vi ans(n);
  while (n) {
    if (t == 0) {
      int z = pr[n];
      assert(z != -1);
      REP(i, z, n) ans[i] = 0;
      n = z;
    } else {
      int z = pr2[n];
      assert(z != -1);
      REP(i, z, n) ans[i] = 1;
      n = z;
    }
    t = 1 - t;
  }
  cout << "Yes\n";
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
  return 0;
}
