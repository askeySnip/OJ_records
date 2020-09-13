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
int n;
ll sumg = 0, suml = 0, a1;
vector<ll> a;

ll check() { return (ceil((double)(a1 + sumg) / 2.0)); }

void cg(int x, int y) {
  if (x > n) return;
  a[x] > 0 ? sumg -= a[x] : suml += a[x];
  a[x] += y;
  a[x] > 0 ? sumg += a[x] : suml -= a[x];
}

int main() {
  gi(n);
  a.resize(n + 1);
  REP(i, 1, n + 1) scanf("%lld", &a[i]);
  REP(i, 2, n + 1) {
    if (a[i] > a[i - 1])
      sumg += a[i] - a[i - 1];
    else
      suml += a[i - 1] - a[i];
  }
  for (int i = n; i; i--) a[i] = a[i] - a[i - 1];
  a1 = a[1];
  printf("%lld\n", check());
  int q;
  gi(q);
  while (q--) {
    int l, r, x;
    giii(l, r, x);
    if (l == 1)
      a1 += x;
    else
      cg(l, x);
    cg(r + 1, -x);
    printf("%lld\n", check());
  }
  return 0;
}
