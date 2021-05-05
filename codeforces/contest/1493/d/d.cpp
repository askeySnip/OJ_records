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
const int maxn = 2e5 + 10;
// data
int n, q;
int nxt[maxn];
map<int, int> cnt_div[maxn];
multiset<int> cnt[maxn];
ll ans = 1;

void add(int i, int x) {
  while (x != 1) {
    int p = nxt[x], cntn = 0;
    while (nxt[x] == p) ++cntn, x /= p;

    int lst = cnt_div[i][p];
    cnt_div[i][p] += cntn;
    int lst_min = 0;
    if ((int)cnt[p].size() == n) {
      lst_min = *(cnt[p].begin());
    }
    if (lst != 0) {
      cnt[p].erase(cnt[p].find(lst));
    }
    cnt[p].insert(cnt_div[i][p]);
    if ((int)cnt[p].size() == n) {
      REP(k, lst_min, (*cnt[p].begin())) { ans = ans * (ll)p % mod; }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  REP(i, 2, maxn) {
    if (nxt[i] == 0) {
      nxt[i] = i;
      if (i > 10000) continue;
      for (int j = i * i; j < maxn; j += i)
        if (nxt[j] == 0) nxt[j] = i;
    }
  }
  REP(i, 0, n) {
    int x;
    cin >> x;
    add(i, x);
  }
  REP(i, 0, q) {
    int a, x;
    cin >> a >> x;
    --a;
    add(a, x);
    cout << ans << "\n";
  }
  return 0;
}
