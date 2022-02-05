/*
AUTHOR: ZhenLi
CREATED: 2021.08.26
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
int ys, ds, m;
vector<string> mz;

void bfs(int x, int y, int& d, int c, int step) {
  int level = 0;
  int n = mz[0].length();
  vector<vi> vist(m, vi(n, 0));
  vist[x][y] = 1;
  queue<ii> q;
  q.push(ii(x, y));
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      ii p = q.front();
      q.pop();
      REP(i, 0, 4) {
        REP(j, 1, step + 1) {
          int tx = p.first + fx[i][0] * j, ty = p.second + fx[i][1] * j;
          if (tx >= 0 && tx < m && ty >= 0 && ty < n && !vist[tx][ty]) {
            if (mz[tx][ty] == (char)(c + '0')) break;
            if (mz[tx][ty] == (char)(3 - c + '0')) continue;
            if (mz[tx][ty] == 'e') {
              d = level + 1;
              return;
            }
            vist[tx][ty] = 1;
            q.push(ii(tx, ty));
          }
        }
      }
    }
    level++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> ys >> ds >> m;
  mz.resize(m);
  REP(i, 0, m) cin >> mz[i];
  int sval, dval;
  REP(i, 0, m) {
    REP(j, 0, mz[i].length()) {
      if (mz[i][j] == 's') bfs(i, j, sval, 1, ys);

      if (mz[i][j] == 'd') bfs(i, j, dval, 2, ds);
    }
  }
  if (sval >= dval)
    cout << "-1" << endl;
  else
    cout << sval << endl;
  return 0;
}
