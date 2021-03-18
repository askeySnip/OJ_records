/*
AUTHOR: lz.askey
CREATED: 18.03.2021 12:45:37
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
vi p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  p.resize(n);
  REP(i, 0, n) cin >> p[i];
  vi t;
  int l = 0, r = 1;
  while (r < n) {
    // int a = 0, b = 0;
    while (r < n && p[r] > p[r - 1]) r++;
    t.push_back(r - l);
    // a = r - l;
    l = r - 1;
    while (r < n && p[r] < p[r - 1]) r++;
    t.push_back(r - l);
    // b = r - l;
    l = r - 1;
    // if(a%2 && b%2) ans.push_back(max(a, b));
  }
  // REP(i, 0, t.size()) error(t[i]);
  int mx = 0, cnt = 0;
  for(int i=0; i<(int)t.size(); i+=2) {
    if(mx < max(t[i], t[i+1])) {
      mx = max(t[i], t[i+1]);
      cnt = 1;
    } else if(mx == max(t[i], t[i+1])) {
      ++cnt;
    }
  }
  // error(mx, cnt);
  if(cnt > 1) {
    printf("0\n");
  } else {
    for(int i=0; i<(int)t.size(); i+=2) {
      if(max(t[i], t[i+1]) == mx) {
        if(t[i]%2 && t[i+1] == t[i]) {
          printf("1\n");
        } else {
          printf("0\n");
        }
      }
    }
  }
  return 0;
}
