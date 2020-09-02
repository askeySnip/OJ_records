/*
ID: leezhen
TASK: practice
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
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
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
const ll inf = 0x3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
int r, g, b;
int rr[210], gg[210], bb[210];
ll f[210][210][210];

ll dp(int i, int j, int k) {
  if (i > r || j > g || k > b) return -inf;
  int c = 0;
  if (i == r) c++;
  if (j == g) c++;
  if (k == b) c++;
  if (c >= 2) return 0;
  if (f[i][j][k] != 0) return f[i][j][k];
  f[i][j][k] = dp(i + 1, j + 1, k) + rr[i] * gg[j];
  f[i][j][k] = max(f[i][j][k], dp(i + 1, j, k + 1) + rr[i] * bb[k]);
  f[i][j][k] = max(f[i][j][k], dp(i, j + 1, k + 1) + gg[j] * bb[k]);
  return f[i][j][k];
}

int main() {
  getIII(r, g, b);
  REP(i, 0, r) getI(rr[i]);
  REP(i, 0, g) getI(gg[i]);
  REP(i, 0, b) getI(bb[i]);
  sort(rr, rr + r, greater<int>());
  sort(gg, gg + g, greater<int>());
  sort(bb, bb + b, greater<int>());
  memset(f, 0, sizeof f);
  printf("%lld\n", dp(0, 0, 0));
  return 0;
}
