/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <assert.h>
#include <bits/stdc++.h>
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

int main() {
  int t = 1;
  while (t--) {
    int n, h, m, k;
    gii(n, h), gii(m, k);
    vector<pair<ll, ll>> v;
    vector<ll> vv;
    REP(i, 0, n) {
      int x, y;
      gii(x, y);
      ll ty = 1ll * x * m + y;
      ll o1 = ty % (m / 2), o2 = (o1 + k) % (m / 2);
      if (o1 < o2) {
        v.emplace_back(o1 + 1, -1);
        v.emplace_back(o2, 1);
      } else {
        v.emplace_back(0, -1);
        v.emplace_back(o2, 1);
        v.emplace_back(o1 + 1, -1);
      }
      vv.push_back(ty);
    }
    sort(all(v));
    ll ans = 0, mx = 0, nw = n;
    if (v.size() == 0 || v[0].ff > 0) mx = n, ans = 0;
    REP(i, 0, v.size()) {
      nw += v[i].ss;
      if (i + 1 < v.size() && v[i + 1].ff == v[i].ff) continue;
      if (mx < nw) mx = nw, ans = v[i].ff;
    }
    printf("%lld %lld\n", n - mx, ans);
    REP(i, 0, n) {
      ll y = vv[i];
      ll o = y % (m / 2);
      ll o1 = ans - k, o2 = ans;
      if (o1 < 0) o1 += m / 2;
      o1 %= m / 2;
      if (o1 < o2) {
        if (o1 < o && o < o2) printf("%d ", i + 1);
      } else {
        if (o < o2 || o > o1) printf("%d ", i + 1);
      }
    }
    printf("\n");
  }
  return 0;
}
