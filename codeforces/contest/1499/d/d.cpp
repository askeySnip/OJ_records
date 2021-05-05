/*
AUTHOR: lz.askey
CREATED: 25.03.2021 23:55:20
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
const int MAXN = 2e7 + 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vi mind(MAXN, -1), val(MAXN);
  mind[1] = 1;
  REP(i, 2, MAXN) {
    if (mind[i] == -1) {
      mind[i] = i;
      if (i > 10000) continue;
      for (int j = i * i; j < MAXN; j += i) {
        if (mind[j] == -1) mind[j] = i;
      }
    }
  }
  REP(i, 2, MAXN) {
    int j = i / mind[i];
    val[i] = val[j] + (mind[i] != mind[j]);
  }
  int t, c, d, x;
  cin >> t;
  while (t--) {
    cin >> c >> d >> x;
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
      if (x % i != 0) continue;
      int k1 = x / i + d;
      if (k1 % c == 0) ans += 1 << val[k1 / c];
      if (i * i == x) continue;
      int k2 = i + d;
      if (k2 % c == 0) ans += 1 << val[k2 / c];
    }
    cout << ans << "\n";
  }
  return 0;
}
