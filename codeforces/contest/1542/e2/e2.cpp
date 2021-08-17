/*
AUTHOR: lz.askey
CREATED: 30.07.2021 17:51:42
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
const int b = 130000;
int w[2][2 * b + 5], s[2][2 * b + 5], ans[505];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  w[0][b] = s[0][b] = 1;
  REP(i, b, 2 * b + 1) s[0][i] = 1;
  REP(i, 1, n + 1) {
    int curs = 1, I = i & 1, J = I ^ 1;
    memset(w[I], 0, sizeof(w[I]));
    memset(s[I], 0, sizeof(s[I]));
    for (int u = i * (i - 1) / 2, j = -u + b; j <= u + b; j++) {
      w[I][j] = curs;
      curs = (0ll + curs - s[J][j] + s[J][j - i] + s[J][j + i] - s[J][j] +
              2ll * m) %
             m;
    }
    for (int j = b - i * (i - 1) / 2, v = (i + 2) * (i + 1) / 2 + b; j <= v;
         j++)
      s[I][j] = (s[I][j - 1] + w[I][j]) % m;
    for (int j = 1; j < i; j++)
      ans[i] = (ans[i] + 1ll * (s[J][(i + 1) * i / 2 + b] - s[J][j + b] + m) %
                             m * (i - j)) %
               m;
  }
  REP(i, 2, n + 1) ans[i] = (ans[i] + 1ll * i * ans[i - 1]) % m;
  cout << ans[n] << endl;
  return 0;
}
