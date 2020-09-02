/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr << #vari << " = " << (vari) << endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size() - 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  int S = (1 << N);
  vector<int64_t> seg(2 * S);
  for (int i = 0; i < S; i++) {
    cin >> seg[S + i];
  }
  for (int i = S - 1; i; --i) {
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }

  int msk = 0;
  auto get_sum = [&](int r) -> int64_t {
    if (r == (1 << N)) return seg[1];

    int64_t ans = 0;
    for (int a = S + (r ^ msk); a; a /= 2, r /= 2) {
      if (r & 1) {
        ans += seg[a ^ 1];
      }
    }
    return ans;
  };

  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      int64_t v;
      cin >> x >> v;
      x--;
      x ^= msk;
      int64_t delta = v - seg[S + x];
      for (int a = S + x; a; a /= 2) seg[a] += delta;
    } else if (t == 2) {
      // reverse
      int k;
      cin >> k;
      msk ^= (1 << k) - 1;
    } else if (t == 3) {
      // flip
      int k;
      cin >> k;
      msk ^= (1 << k);
    } else if (t == 4) {
      int l, r;
      cin >> l >> r;
      l--;  // half-open
      cout << get_sum(r) - get_sum(l) << '\n';
    } else
      assert(false);
  }

  return 0;
}
