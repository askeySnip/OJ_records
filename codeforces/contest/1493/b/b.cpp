/*
AUTHOR: lz.askey
CREATED: 19.03.2021 00:32:15
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
int mirr[10][2] = {{0, 0}, {1, 1},  {2, 5},  {3, -1}, {4, -1},
                   {5, 2}, {6, -1}, {7, -1}, {8, 8},  {9, -1}};

// data

bool check(int a, int b, int sa, int sb) {
  if (a >= sa || b >= sb) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  gi(t);
  while (t--) {
    int h, m;
    int th, tm;
    gii(h, m);
    scanf("%d:%d", &th, &tm);
    int ch = th, cm = tm;
    do {
      int a = ch % 10, b = (ch / 10) % 10;
      int c = cm % 10, d = (cm / 10) % 10;
      a = mirr[a][1], b = mirr[b][1], c = mirr[c][1], d = mirr[d][1];
      // error(a, b, c, d);
      if (a == -1 || b == -1 || c == -1 || d == -1) {
        ++cm;
        if (cm == m) cm = 0, ++ch;
        if (ch == h) ch = 0;
      } else {
        if (check(c * 10 + d, a * 10 + b, h, m)) {
          printf("%d%d:%d%d\n", mirr[b][1], mirr[a][1], mirr[d][1], mirr[c][1]);
          break;
        } else {
          ++cm;
          if (cm == m) cm = 0, ++ch;
          if (ch == h) ch = 0;
        }
      }
    } while (ch != th || cm != tm);
  }
  return 0;
}
