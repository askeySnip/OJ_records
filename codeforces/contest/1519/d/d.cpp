/*
AUTHOR: lz.askey
CREATED: 05.05.2021 19:15:22
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
int n;
vector<ll> a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n), b.resize(n);
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) cin >> b[i];
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  REP(i, 0, n) dp[i][i] = a[i] * b[i];
  REP(i, 0, n - 1) dp[i][i + 1] = a[i] * b[i + 1] + b[i] * a[i + 1];
  REP(i, 2, n) {
    REP(j, 0, n - i) {
      dp[j][j + i] = dp[j + 1][j + i - 1] + b[j] * a[j + i] + b[j + i] * a[j];
    }
  }
  vector<ll> presum(n, 0), sufsum(n, 0);
  presum[0] = a[0] * b[0];
  sufsum[n - 1] = a[n - 1] * b[n - 1];
  REP(i, 1, n) presum[i] = presum[i - 1] + a[i] * b[i];
  for (int i = n - 2; i >= 0; i--) sufsum[i] = sufsum[i + 1] + a[i] * b[i];
  ll ans = presum[n - 1];
  REP(i, 1, n) {
    REP(j, 0, n - i) {
      ll cur = dp[j][j + i];
      if (j) cur += presum[j - 1];
      if (j + i + 1 < n) cur += sufsum[j + i + 1];
      ans = max(ans, cur);
    }
  }
  cout << ans << "\n";
  return 0;
}
