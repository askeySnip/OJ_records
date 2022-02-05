/*
AUTHOR: $%U%$
CREATED: $%D%$.$%M%$.$%Y%$ $%h%$:$%m%$:$%s%$
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
#include <functional>
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
class BIT {
 public:
  BIT(int n) { t.assign(n + 1, 0); }
  void update(int pos, int val) {
    int p = pos + 1;
    for (; p < (int)t.size(); p += (p & (-p))) {
      t[p] += val;
    }
  }
  int sum(int pos) {
    ++pos;
    int ret = 0;
    for (; pos; pos -= (pos & (-pos))) {
      ret += t[pos];
    }
    return ret;
  }

 private:
  vi t;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, kase = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> pos[10];
    BIT cnt(n);
    REP(i, 0, n) pos[s[i] - '0'].insert(i), cnt.update(i, 1);
    while (1) {
      bool f = false;
      REP(i, 0, 10) {
        vi e1, e2;
        for (auto it = pos[i].begin(); it != pos[i].end(); it++) {
          int v = *it;
          auto p_v = pos[(i + 1) % 10].lower_bound(v);
          if (p_v == pos[(i + 1) % 10].end()) break;
          int v2 = *p_v;
          if (cnt.sum(v) == cnt.sum(v2) - 1) {
            f = true;
            e1.push_back(v);
            e2.push_back(v2);
          }
        }
        for (auto e : e1) pos[i].erase(e), cnt.update(e, -1);
        for (auto e : e2)
          pos[(i + 1) % 10].erase(e), pos[(i + 2) % 10].insert(e);
      }
      if (!f) break;
    }
    int rn = 0;
    REP(i, 0, 10) rn += pos[i].size();
    vector<char> ans(rn);
    REP(i, 0, 10) for (auto v : pos[i]) ans[cnt.sum(v) - 1] = '0' + i;
    cout << "Case #" << ++kase << ": ";
    REP(i, 0, rn) cout << ans[i];
    cout << '\n';
  }
  return 0;
}
