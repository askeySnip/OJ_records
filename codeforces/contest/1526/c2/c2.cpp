/*
AUTHOR: lz.askey
CREATED: 21.08.2021 17:24:26
LANG: C++14
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
class FT {
 private:
  vector<ll> t;

 public:
  FT(int n) { t.assign(n, 0); }
  void add(int p, int val) {
    for (; p < t.size(); p += p & (-p)) {
      t[p] += val;
    }
  }

  ll sum(int p) {
    ll ret = 0;
    for (; p; p -= p & (-p)) ret += t[p];
    return ret;
  }
};
// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n + 1);
  FT ft(n + 1);
  vii neg;
  int ans = 0;
  REP(i, 1, n + 1) {
    cin >> a[i];
    if (a[i] >= 0)
      ++ans, ft.add(i, a[i]);
    else
      neg.emplace_back(a[i], i), a[i] = 0;
  }
  sort(all(neg), greater<ii>());
  vi pre(n + 1);
  REP(i, 1, n + 1) pre[i] = i - 1;
  REP(i, 0, sz(neg)) {
    if (ft.sum(neg[i].second) < -neg[i].first) continue;
    int j = neg[i].second, w = -neg[i].first;
    vi path;
    while (w) {
      // error(w, j);
      path.push_back(j);
      int v = min(w, a[j]);
      ft.add(j, -v);
      a[j] -= v;
      w -= v;
      if (a[j] == 0) j = pre[j];
    }
    if (j == path.back()) path.pop_back();
    for (auto p : path) pre[p] = j;
    ++ans;
  }
  cout << ans << '\n';
  return 0;
}
