/*
AUTHOR: lz.askey
CREATED: 28.12.2021 23:26:39
LANG: C++14
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
typedef vector<pair<int, int>> vii;
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
int f(int x) {
  for (int i = 0;; i++) {
    if ((1 << i) >= x) {
      return (1 << i) - x;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  REP(i, 0, n) cin >> a[i];
  map<int, pair<ii, ii>> m;
  priority_queue<int> pq;
  REP(i, 0, n) {
    pq.push(a[i]);
    m[a[i]].first = make_pair(0, i + 1);
  }
  while (!pq.empty()) {
    int od = pq.top();
    pq.pop();
    if (!pq.empty() && pq.top() == od) continue;
    if (od != 1) {
      int nxt = f(od);
      pq.push(nxt);
      ii se = m[od].first;
      se.first++;
      if (m[nxt].first < se) {
        m[nxt].second = m[nxt].first;
        m[nxt].first = se;
      } else if (m[nxt].second < se) {
        m[nxt].second = se;
      }
    }
  }
  int ra = 0, rb = 0, rc = 0;
  for (auto& nx : m) {
    pair<ii, ii> tg = nx.second;
    if (tg.first.second == 0 || tg.second.second == 0) continue;
    if (rc < tg.first.first + tg.second.first) {
      rc = tg.first.first + tg.second.first;
      ra = tg.first.second;
      rb = tg.second.second;
    }
  }
  cout << ra << " " << rb << " " << rc << "\n";
  return 0;
}
