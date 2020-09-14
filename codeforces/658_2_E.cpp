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
const int N = 1e5 + 10;
int n, x, y, b[N], a[N];
vi ind[N], hist[N];
bool mis[N];

int main() {
  int t;
  gi(t);
  while (t--) {
    giii(n, x, y);
    REP(i, 0, n + 2) ind[i].clear(), hist[i].clear(), a[i] = 0, mis[i] = false;
    REP(i, 1, n + 1) gi(b[i]), ind[b[i]].push_back(i);
    REP(i, 1, n + 2) hist[ind[i].size()].push_back(i);
    int idx = n;
    REP(k, 1, x + 1) {
      while (hist[idx].empty()) idx--;
      int col = hist[idx].back();
      a[ind[col].back()] = col;
      ind[col].pop_back();
      hist[idx].pop_back();
      hist[idx - 1].push_back(col);
    }
    while (idx > 0 && hist[idx].empty()) idx--;
    vi ve;
    // f is the most frequent, n is tot, then must have 2*f - n matches.
    if (idx * 2 > 2 * n - x - y) {
      printf("NO\n");
      continue;
    }
    REP(i, 1, idx + 1) {
      for (int col : hist[i]) {
        ve.insert(ve.end(), ind[col].begin(), ind[col].end());
      }
    }
    int mismatch = n - y;
    auto makemismatch = [&](int i) {
      a[i] = hist[0][0];
      mismatch--;
      mis[i] = true;
    };
    REP(i, 0, n - x) {
      a[ve[i]] = b[ve[(i + (n - x) / 2) % (n - x)]];
      if (a[ve[i]] == b[ve[i]]) makemismatch(ve[i]);
    }
    for (int i = 0; mismatch > 0; i++) {
      if (!mis[ve[i]]) makemismatch(ve[i]);
    }
    printf("YES\n");
    REP(i, 1, n + 1) printf("%d ", a[i]);
    printf("\n");
  }

  return 0;
}
