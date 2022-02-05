/*
AUTHOR: lz.askey
CREATED: 21.08.2021 17:24:26
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  map<char, int> id{{'A', 0}, {'N', 1}, {'O', 2}, {'T', 3}};
  string cset = "ANOT";
  ll flips[4][4];
  while (t--) {
    string s;
    cin >> s;
    vi cnt(4, 0);
    int n = s.length();
    memset(flips, 0, sizeof flips);
    REP(i, 0, n) cnt[id[s[i]]]++;
    REP(i, 0, 4) {
      int curr = 0;
      REP(j, 0, n) {
        flips[i][id[s[j]]] += curr;
        if (id[s[j]] == i) ++curr;
      }
    }
    ll best = -1;
    vi ans;
    vi v = {0, 1, 2, 3};
    do {
      ll curr = 0;
      REP(i, 0, 4) {
        REP(j, i + 1, 4) { curr += flips[v[j]][v[i]]; }
      }
      if (curr > best) {
        best = curr;
        ans = v;
      }
    } while (next_permutation(all(v)));

    for (auto& it : ans) REP(i, 0, cnt[it]) cout << cset[it];
    cout << '\n';
  }
  return 0;
}
