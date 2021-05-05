/*
AUTHOR: lz.askey
CREATED: 27.03.2021 01:04:03
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
int n;
int a[100010], dif[100010];

void solve() {
  int mx = 0;
  REP(i, 0, n) mx = max(mx, a[i]);
  REP(i, 0, n - 1) dif[i] = a[i + 1] - a[i];
  int n1 = 2e9, n2 = 2e9, cnt = 0, tmp = 0;
  bool f = true;
  REP(i, 0, n - 1) {
    if (dif[i] < 0) {
      if (n1 == 2e9)
        n1 = dif[i];
      else {
        if (n1 != dif[i]) {
          f = false;
          break;
        }
      }
    }
    if (dif[i] > 0) {
      if (n2 == 2e9)
        n2 = dif[i];
      else {
        if (n2 != dif[i]) {
          f = false;
          break;
        }
      }
    }
    cnt += (dif[i] == dif[0]);
    tmp += (dif[i] == 0);
  }
  if (cnt == n - 1)
    cout << "0\n";
  else if (f && !tmp && (n2 - n1) > mx)
    cout << n2 - n1 << " " << n2 << endl;
  else
    cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, 0, n) cin >> a[i];
    solve();
  }
  return 0;
}
