/*
AUTHOR: lz.askey
CREATED: 17.03.2021 21:41:13
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
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
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

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
int n;
int a[110], b[110];
int tm[110];

void solve() {
  int t = 0;
  rep(i, 1, n + 1) {
    t += a[i] - b[i - 1] + tm[i];
    if (i >= n) break;
    if (t + (b[i] - a[i] + 1) / 2 < b[i])
      t = b[i];
    else
      t += (b[i] - a[i] + 1) / 2;
    // error(i, t);
  }
  cout << t << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  a[0] = b[0] = 0;
  while (t--) {
    cin >> n;
    rep(i, 1, n + 1) { cin >> a[i] >> b[i]; }
    rep(i, 1, n + 1) cin >> tm[i];
    solve();
  }
  return 0;
}
