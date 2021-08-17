/*
AUTHOR: lz.askey
CREATED: 23.07.2021 13:57:23
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
const int mod = 998244353;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
const int maxn = 500 + 5;
int n, x, y, cur;
// b[i][j] means in ith col, # of j
// f[i] means ith row status
int a[maxn * 2][maxn], b[maxn][maxn], f[maxn];
// c[i][j] means ith col, number j's positions.
vector<int> c[maxn][maxn];
vii v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, 1, n + 1) {
      REP(j, 1, n + 1) {
        b[i][j] = 0;
        c[i][j].clear();
      }
    }
    REP(i, 1, n * 2 + 1) {
      f[i] = 0;
      REP(j, 1, n + 1) {
        cin >> a[i][j];
        b[j][a[i][j]]++;
        c[j][a[i][j]].push_back(i);
      }
    }
    int top = 0, tail = 0;
    int cnt = 0, idx = 1;
    ll ans = 1;
    v.clear();
    REP(i, 1, n + 1) {
      REP(j, 1, n + 1) {
        if (b[i][j] == 1) {
          tail++;
          v.emplace_back(i, j);
        }
      }
    }
    while (cnt < n) {
      if (top < tail) {
        x = v[top].ff;
        y = v[top].ss;
        if (b[x][y] != 1) {
          top++;
          continue;
        }
        for (auto i : c[x][y]) {
          if (f[i] == 0) {
            cur = i;
            break;
          }
        }
      } else {
        while (f[idx] != 0) {
          idx++;
        }
        cur = idx;
        ans = ans * 2 % mod;
      }
      f[cur] = 1;
      ++cnt;
      REP(i, 1, n + 1) { b[i][a[cur][i]] = 0; }
      REP(i, 1, n + 1) {
        for (auto j : c[i][a[cur][i]]) {
          if (f[j] == 0) {
            f[j] = 2;
            REP(k, 1, n + 1) {
              b[k][a[j][k]]--;
              if (b[k][a[j][k]] == 1) {
                tail++;
                v.emplace_back(k, a[j][k]);
              }
            }
          }
        }
      }
      top++;
    }
    int s = 0;
    cout << ans << "\n";
    REP(i, 1, n * 2 + 1) {
      if (f[i] == 1) {
        ++s;
        if (s < n)
          cout << i << " ";
        else
          cout << i << "\n";
      }
    }
  }
  return 0;
}
