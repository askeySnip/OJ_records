/*
AUTHOR: lz.askey
CREATED: 20.08.2021 16:48:24
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
const int maxn = (1 << 18) + 10;
string s;
int k;
int sg[maxn * 4];

int op(int p) {
  if (s[p] == '?')
    return sg[p * 2] + sg[p * 2 + 1];
  else if (s[p] == '1')
    return sg[p * 2];
  else
    return sg[p * 2 + 1];
}

void build(int p) {
  if (p >= (1 << k))
    sg[p] = 1;
  else {
    build(p * 2);
    build(p * 2 + 1);
    sg[p] = op(p);
  }
}

void update(int p) {
  while (p) {
    sg[p] = op(p);
    // cout << p << ' ' << sg[p] << " " << op(1) << endl;
    p /= 2;
  }
}

void print() {
  REP(i, 1, (1 << (k + 1))) { cout << sg[i] << ' '; }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k;
  cin >> s;
  s += ' ';
  reverse(all(s));
  build(1);
  // print();
  int q;
  cin >> q;
  REP(i, 0, q) {
    int p;
    char c;
    cin >> p >> c;
    p = (1 << k) - p;
    s[p] = c;
    update(p);
    // print();
    cout << sg[1] << '\n';
  }
  return 0;
}
