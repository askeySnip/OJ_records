/*
AUTHOR: lz.askey
CREATED: 17.08.2021 20:07:23
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
int f[2][2005];
int getf(int id, int x) {
  return x == f[id][x] ? x : f[id][x] = getf(id, f[id][x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  REP(i, 1, n + 1) f[0][i] = f[1][i] = i;
  REP(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    int x = getf(0, u), y = getf(0, v);
    f[0][x] = y;
  }
  REP(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    int x = getf(1, u), y = getf(1, v);
    f[1][x] = y;
  }
  vii ans;
  REP(i, 1, n + 1) {
    REP(j, i + 1, n + 1) {
      if (getf(0, i) != getf(0, j) && getf(1, i) != getf(1, j)) {
        ans.emplace_back(i, j);
        f[0][getf(0, i)] = getf(0, j);
        f[1][getf(1, i)] = getf(1, j);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.ff << " " << i.ss << "\n";
  return 0;
}
