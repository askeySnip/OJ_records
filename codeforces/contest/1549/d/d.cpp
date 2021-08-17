/*
AUTHOR: lz.askey
CREATED: 02.08.2021 23:55:11
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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> b(n, vector<ll>(20, 0));
    vi log(n + 1, 0);
    log[1] = 0;
    REP(i, 2, n + 1) log[i] = log[i / 2] + 1;
    REP(i, 0, n) cin >> a[i];
    REP(i, 1, n) b[i][0] = abs(a[i] - a[i - 1]);
    REP(i, 1, 20) {
      REP(j, 1, n) {
        int k = min(n - 1, j + (1 << (i - 1)));
        b[j][i] = gcd(b[j][i - 1], b[k][i - 1]);
      }
    }
    int ans = 1;
    REP(i, 1, n) {
      int l = i, r = n;
      while (l < r - 1) {
        int mid = (l + r) / 2;
        int k = log[mid - i + 1];
        if (gcd(b[i][k], b[mid - (1 << k) + 1][k]) != 1)
          l = mid;
        else
          r = mid;
      }
      if (b[i][0] != 1) ans = max(ans, l - i + 2);
    }
    cout << ans << "\n";
  }
  return 0;
}
