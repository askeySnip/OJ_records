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
bool vis[100002];
ll pri[100002], tot, n, x, sum, ans, ia;

int main() {
  scanf("%lld", &n);
  for (ll i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri[++tot] = i;
      if (i <= sqrt(n)) {
        for (ll j = i * i; j <= n; j += i) vis[j] = 1;
      }
    }
  }
  memset(vis, 0, sizeof vis);
  ll k = sqrt(tot);
  sum = n, ans = 1;
  for (ll i = 1; i <= tot; i++) {
    if (i >= k && ans * pri[i - k + 1] > n) break;
    printf("B %lld", pri[i]);
    cout << endl;
    ll num = 0;
    for (ll j = pri[i]; j <= n; j += pri[i]) {
      if (!vis[j]) {
        ++num, --sum;
        vis[j] = 1;
      }
    }
    scanf("%lld", &x);
    if (x != num) {
      for (ll kk = pri[i]; kk <= n; kk *= pri[i]) {
        printf("A %lld", kk);
        cout << endl;
        scanf("%lld", &x);
        if (x)
          ans *= pri[i];
        else
          break;
      }
    }
    if ((i == tot || i % k == 0) && !ia) {
      printf("A 1");
      cout << endl;
      scanf("%lld", &x);
      if (x != sum) {
        for (ll j = i - k + 1; j <= i; j++) {
          for (ll kk = pri[j]; kk <= n; kk *= pri[j]) {
            printf("A %lld", kk);
            cout << endl;
            scanf("%lld", &x);
            if (x)
              ans *= pri[j], ia = 1;
            else
              break;
          }
          if (ia) break;
        }
      }
    }
  }
  printf("C %lld", ans);
  cout << endl;
  return 0;
}
