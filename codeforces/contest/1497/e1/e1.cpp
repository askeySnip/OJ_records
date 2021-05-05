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
    int l = 0, ans = 1;
    map<int, int> lst;
    REP(i, 0, n) {
      if (lst.find(a[i]) != lst.end() && lst[a[i]] >= l) {
        ++ans;
        l = i;
      }
      lst[a[i]] = i;
    }
    cout << ans << "\n";
  }
  return 0;
}
