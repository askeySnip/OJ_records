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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data

int main() {
  char s[1000010];
  int n, m;
  getII(n, m);
  int cnt[8] = {0, 1, 1, 2, 1, 2, 2, 3};
  if (n >= 4) {
    REP(i, 0, n) getS(s);
    printf("-1\n");
  } else {
    if (n == 1) {
      REP(i, 0, n) getS(s);
      printf("0\n");
    } else if (n == 2) {
      char mt[2][1000010];
      getS(mt[0]);
      getS(mt[1]);
      vector<vi> f(m, vi(4, 0));
      int t = char2Int(mt[0][0]) + char2Int(mt[1][0]) * 2;
      REP(i, 0, 4) { f[0][t ^ i] = cnt[i]; }
      REP(i, 1, m) {
        t = char2Int(mt[0][i]) + char2Int(mt[1][i]) * 2;
        REP(j, 0, 4) f[i][t ^ j] = cnt[j];
        REP(j, 0, 4) {
          int v = inf;
          REP(k, 0, 4) {
            int c = cnt[j] + cnt[k];
            if (c % 2) v = min(v, f[i - 1][k]);
          }
          f[i][j] += v;
        }
      }
      int ans = inf;
      REP(i, 0, 4) ans = min(ans, f[m - 1][i]);
      printf("%d\n", ans);
    } else {
      char mt[3][1000010];
      REP(i, 0, 3) getS(mt[i]);
      vector<vi> f(m, vi(8, 0));
      int t =
          char2Int(mt[0][0]) + char2Int(mt[1][0]) * 2 + char2Int(mt[2][0]) * 4;
      REP(i, 0, 8) { f[0][t ^ i] = cnt[i]; }
      REP(i, 1, m) {
        t = char2Int(mt[0][i]) + char2Int(mt[1][i]) * 2 +
            char2Int(mt[2][i]) * 4;
        REP(j, 0, 8) f[i][t ^ j] = cnt[j];
        REP(j, 0, 8) {
          int v = inf;
          REP(k, 0, 8) {
            if (((cnt[j & 3] + cnt[k & 3]) & 1) &&
                ((cnt[j & 6] + cnt[k & 6]) & 1))
              v = min(v, f[i - 1][k]);
          }
          f[i][j] += v;
        }
      }
      int ans = inf;
      REP(i, 0, 8) ans = min(ans, f[m - 1][i]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
