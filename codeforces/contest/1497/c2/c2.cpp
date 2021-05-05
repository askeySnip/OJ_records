/*
AUTHOR: lz.askey
CREATED: 24.03.2021 21:15:11
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
vi prims;

// data
void sieve() {
  bitset<100010> bs;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < 100010; i++) {
    if (bs[i]) {
      prims.push_back(i);
      for (ll j = i * i; j < 100010; j += i) bs[j] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, k;
  cin >> t;
  sieve();
  while (t--) {
    cin >> n >> k;
    while (k > 3) {
      printf("%d ", 1);
      --k, --n;
    }
    if (n % 2) {
      printf("1 %d %d\n", n / 2, n / 2);
    } else {
      if (n % 3 == 0) {
        printf("%d %d %d\n", n / 3, n / 3, n / 3);
      } else if (n % 4 == 0) {
        printf("%d %d %d\n", n / 4, n / 4, n / 2);
      } else {
        bool f = false;
        REP(i, 1, prims.size()) {
          if (prims[i] > n) break;
          if (n % prims[i] == 0) {
            int o = n / prims[i];
            printf("%d %d %d\n", o, o * (prims[i] / 2), o * (prims[i] / 2));
            f = true;
            break;
          }
        }
        if (!f) {
          printf("%d %d %d\n", 2, 2 * (n / 4), 2 * (n / 4));
        }
      }
    }
  }
  return 0;
}
