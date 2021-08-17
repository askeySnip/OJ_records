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
ll a[100010], b[100010], s[100010];

int main() {
  int t, kase = 0;
  gi(t);
  while (t--) {
    int n, m;
    gii(n, m);
    REP(i, 0, n) scanf("%lld %lld", &a[i], &b[i]);
    REP(i, 0, m) scanf("%lld", &s[i]);
    vector<ll> ans(m);
    set<pair<ll, ll>> interval;
    REP(i, 0, n) interval.insert(mp(b[i], a[i]));
    REP(i, 0, m) {
      auto it = interval.lower_bound(mp(s[i], s[i]));
      if (it != interval.end()) {
        if (it->first >= s[i] && it->second <= s[i]) {
          ll ed = it->first, st = it->second;
          interval.erase(it);
          ans[i] = s[i];
          if (st <= s[i] - 1) interval.insert(mp(s[i] - 1, st));
          if (s[i] + 1 <= ed) interval.insert(mp(ed, s[i] + 1));
          continue;
        }
        ll d = it->second - s[i];
        if (it == interval.begin()) {
          ll st = it->second, e = it->first;
          interval.erase(it);
          if (st + 1 <= e) interval.insert(mp(e, st + 1));
          ans[i] = st;
        } else {
          --it;
          ll td = s[i] - (it->first);
          if (td <= d) {
            ans[i] = it->first;
            ll ed = it->first, st = it->second;
            interval.erase(it);
            if (st <= ed - 1) interval.insert(mp(ed - 1, st));
          } else {
            ++it;
            ans[i] = it->second;
            ll ed = it->first, st = it->second;
            interval.erase(it);
            if (st + 1 <= ed) interval.insert(mp(ed, st + 1));
          }
        }
      } else {
        --it;
        ans[i] = it->first;
        ll ed = it->first, st = it->second;
        interval.erase(it);
        if (st + 1 <= ed) interval.insert(mp(ed - 1, st));
      }
    }
    printf("Case #%d:", ++kase);
    REP(i, 0, ans.size()) printf(" %lld", ans[i]);
    printf("\n");
  }
  return 0;
}
