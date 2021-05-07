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
const int N = 200010;
// data
int n;
int su[N], sk[N];
unordered_map<int, vector<ll>> u;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, 0, n)
    cin >> su[i];
    REP(i, 0, n)
    cin >> sk[i];
    REP(i, 0, n)
    u[su[i]].push_back(sk[i]);
    for (auto& i : u) {
      sort(all(i.second));
      reverse(all(i.second));
      REP(j, 1, sz(i.second)) { i.second[j] += i.second[j - 1]; }
      // REP(j, 0, sz(i.second)) error(i.second[j]);
    }
    // notice: must do the erase op of the map. otherwise cause TLE.
    REP(p, 1, n + 1) {
      ll ans = 0;
      vi dl;
      for (auto& i : u) {
        if (sz(i.second) < p) {
          dl.push_back(i.first);
          continue;
        }
        int r = sz(i.second) % p;
        ans += i.second[sz(i.second) - r - 1];
      }
      for (auto i : dl) u.erase(i);
      cout << ans << " ";
    }
    cout << "\n";
    u.clear();
  }
  return 0;
}
