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
int add(int a, int b) { return (a + b) % mod; }
// data
int n;
string s[100010];
map<ii, int> mem;

bool check(int i, int e1, int j, int e2) {
  int is = 0, js = 0;
  if (is == e1) ++is;
  if (js == e2) ++js;
  while (is < s[i].length() && js < s[j].length()) {
    if (s[i][is] == s[j][js]) {
      ++is;
      ++js;
    } else {
      if (s[i][is] > s[j][js]) {
        return false;
      } else
        return true;
    }
    if (is == e1) ++is;
    if (js == e2) ++js;
  }
  if (is >= s[i].length()) return true;
  if (js >= s[j].length()) return false;
}

int dp(int i, int idx) {
  // error(i, idx);
  if (i == n) return 1;
  if (mem.find({i, idx}) != mem.end()) return mem[{i, idx}];
  int ans = 0;
  REP(j, 0, s[i].length() + 1) {
    if (check(i - 1, idx, i, j)) {
      ans = add(ans, dp(i + 1, j));
    }
  }
  // error(i, idx, ans);
  return mem[{i, idx}] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  REP(i, 0, n) cin >> s[i];
  int ans = 0;
  REP(i, 0, s[0].length() + 1) { ans = add(ans, dp(1, i)); }
  printf("%d\n", ans);
  return 0;
}
