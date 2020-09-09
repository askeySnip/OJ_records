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
// binary lifting intro in : https://codeforces.com/blog/entry/61364

int main() {
  int n, q;
  gii(n, q);
  vi a(n + 1), ans(q), leftBound(q);
  vector<vi> endHere(n + 1);
  REP(i, 1, n + 1) gi(a[i]), a[i] = i - a[i];
  REP(i, 0, q) {
    int x, y;
    gii(x, y);
    int l = 1 + x, r = n - y;
    leftBound[i] = l;
    endHere[r].push_back(i);
  }
  vi BIT(n + 1);
  int global = 0;
  REP(r, 1, n + 1) {
    int target = a[r];
    if (target >= 0) {
      // find rightmost pos such that s[pos] >= target
      int pos = 0, cur = global;
      for (int jump = 1 << __lg(n); jump >= 1; jump /= 2) {
        if (pos + jump <= r && cur - BIT[pos + jump] >= target) {
          pos += jump, cur -= BIT[pos];
        }
      }
      // Increment prefix(+1 on whole array, -1 on suffix)
      ++global;
      for (int i = pos + 1; i <= n; i += i & (-i)) {
        ++BIT[i];
      }
    }
    for (int iquery : endHere[r]) {
      ans[iquery] = global;
      for (int i = leftBound[iquery]; i > 0; i -= i & (-i)) {
        ans[iquery] -= BIT[i];
      }
    }
  }
  REP(i, 0, q) { printf("%d\n", ans[i]); }
  return 0;
}
