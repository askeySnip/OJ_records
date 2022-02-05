/*
AUTHOR: lz.askey
CREATED: 17.08.2021 20:07:23
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
class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return i == p[i] ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

// data

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  UnionFind uf1(n + 1), uf2(n + 1);
  REP(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    uf1.unionSet(u, v);
  }
  REP(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    uf2.unionSet(u, v);
  }
  vii ans;
  vi v1, v2;
  REP(i, 1, 2) {
    REP(j, i + 1, n + 1) {
      if (!uf1.isSameSet(i, j) && !uf2.isSameSet(i, j)) {
        ans.emplace_back(i, j);
        uf1.unionSet(i, j);
        uf2.unionSet(i, j);
      }
    }
  }
  int idx1 = 2, idx2 = 2;
  while (true) {
    while (idx1 <= n && uf1.isSameSet(1, idx1)) ++idx1;
    if (idx1 > n) break;
    while (idx2 <= n && uf2.isSameSet(1, idx2)) ++idx2;
    if (idx2 > n) break;

    ans.emplace_back(idx1, idx2);
    uf1.unionSet(idx1, idx2);
    uf2.unionSet(idx1, idx2);
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.ff << " " << i.ss << "\n";
  return 0;
}
