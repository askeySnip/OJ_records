/*
AUTHOR: lz.askey
CREATED: 24.03.2021 21:15:11
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
const int MAXA = 1e7 + 10;

// data
int n, k;
vi a;
int mind[MAXA];
vi cnt(MAXA);

int mask(int x) {
  int ans = 1, lst = 0, cnt = 0;
  while (x > 1) {
    int p = mind[x];
    if (lst == p)
      ++cnt;
    else {
      if (cnt & 1) ans *= lst;
      lst = p;
      cnt = 1;
    }
    x /= p;
  }
  if (cnt & 1) ans *= lst;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  REP(i, 2, MAXA) {
    if (mind[i] == 0) {
      mind[i] = i;
      if (i > 10000) continue;
      for (int j = i * i; j < MAXA; j += i) {
        if (mind[j] == 0) mind[j] = i;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    a.resize(n);
    REP(i, 0, n) {
      cin >> a[i];
      a[i] = mask(a[i]);
    }
    vector<vi> mleft(n, vi(k + 1));  // mleft[i][j] = l means from a[l] to a[i]
                                     // all nums distinct after k changes.
    REP(j, 0, k + 1) {
      int l = n, now = 0;
      for (int i = n - 1; i >= 0; i--) {
        while (l - 1 >= 0 && now + (cnt[a[l - 1]] > 0) <= j) {
          l--;
          now += (cnt[a[l]] > 0);
          cnt[a[l]]++;
        }
        mleft[i][j] = l;
        if (cnt[a[i]] > 1) now--;
        cnt[a[i]]--;
      }
    }
    vector<vi> dp(n + 1, vi(k + 1, inf));
    for (auto& c : dp[0]) c = 0;
    REP(i, 1, n + 1) {
      REP(j, 0, k + 1) {
        if (j > 0) dp[i][j] = dp[i][j - 1];
        REP(lst, 0, j + 1) {
          dp[i][j] = min(dp[i][j], dp[mleft[i - 1][lst]][j - lst] + 1);
        }
      }
    }
    int ans = inf;
    for (auto& c : dp.back()) ans = min(ans, c);
    cout << ans << "\n";
  }
  return 0;
}
