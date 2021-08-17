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
ll c;
pair<ll, ll> lr[100010];

int main() {
  int t, kase = 0;
  gi(t);
  while (t--) {
    gi(n);
    scanf("%lld", &c);
    REP(i, 0, n) { scanf("%lld %lld", &lr[i].first, &lr[i].second); }
    vector<ll> ind;
    REP(i, 0, n) {
      ind.push_back(lr[i].first);
      ind.push_back(lr[i].second);
    }
    sort(all(ind));
    auto last = unique(all(ind));
    ind.erase(last, ind.end());
    vector<int> cnt(ind.size() + 1, 0);
    vector<int> tcnt(ind.size(), 0);
    REP(i, 0, n) {
      auto l = lower_bound(all(ind), lr[i].first) - ind.begin();
      auto r = lower_bound(all(ind), lr[i].second) - ind.begin();
      //   for (int j = l + 1; j <= r; j++) cnt[j]++;
      //   for (int j = l + 1; j < r; j++) tcnt[j]++;
      cnt[l + 1] += 1;
      cnt[r + 1] += -1;
      tcnt[l + 1] += 1;
      tcnt[r] += -1;
    }
    REP(i, 1, ind.size()) cnt[i] += cnt[i - 1], tcnt[i] += tcnt[i - 1];
    priority_queue<ii> pq;
    REP(i, 0, ind.size()) {
      pq.push(mp(cnt[i], i));
      pq.push(mp(tcnt[i], i + ind.size()));
    }
    ll ans = n;
    while (!pq.empty()) {
      ii p = pq.top();
      pq.pop();
      if (p.second == 0) break;
      if (p.second < ind.size()) {
        ll len = ind[p.second] - ind[p.second - 1];
        ll tp = min(len - 1, c);
        ans += tp * cnt[p.second];
        c -= tp;
      } else {
        ans += tcnt[p.second - ind.size()];
        --c;
      }
      if (!c) break;
    }
    printf("Case #%d: %lld\n", ++kase, ans);
  }
  return 0;
}
