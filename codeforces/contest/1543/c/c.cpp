/*
AUTHOR: lz.askey
CREATED: 24.07.2021 17:43:48
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
const double scal = 1e6;

double helper(int a, int b, int c, int v) {
  double ans = c / scal;
  if (a > 0) {
    if (a <= v) {  // a <= v
      if (b > 0)   // b != 0
        ans += a / scal * (1.0 + helper(0, b + a / 2, c + a / 2, v));
      else  // b == 0
        ans += a / scal * (1.0 + helper(0, 0, c + a, v));
    } else {      // a > v
      if (b > 0)  // b != 0
        ans += a / scal * (1.0 + helper(a - v, b + v / 2, c + v / 2, v));
      else  // b == 0
        ans += a / scal * (1.0 + helper(a - v, 0, c + v, v));
    }
  }
  if (b > 0) {     // b!= 0
    if (b <= v) {  // b<=v
      if (a > 0)   // a != 0
        ans += b / scal * (1.0 + helper(a + b / 2, 0, c + b / 2, v));
      else  // a == 0
        ans += b / scal * (1.0 + helper(0, 0, c + b, v));
    } else {      // b > v
      if (a > 0)  // a != 0
        ans += b / scal * (1.0 + helper(a + v / 2, b - v, c + v / 2, v));
      else  // a == 0
        ans += b / scal * (1.0 + helper(0, b - v, c + v, v));
    }
  }
  // error(a, b, c, ans);
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    double c, m, p, v;
    scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
    printf("%.12lf\n", helper(round(c * scal), round(m * scal), round(p * scal),
                              round(v * scal)));
  }
  return 0;
}
