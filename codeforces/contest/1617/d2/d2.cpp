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

void deal1(vi& pos0, int one, vi& im, vi& cr) {
  for (auto v : pos0) {
    int x1, x2;
    cout << "? " << one << " " << v + 1 << " " << v + 2 << endl;
    cin >> x1;
    cout << "? " << one << " " << v + 3 << " " << v + 2 << endl;
    cin >> x2;
    if (x1 + x2 == 0) {
      im.push_back(v + 1);
      im.push_back(v + 2);
      im.push_back(v + 3);
    } else if (x1 + x2 == 2) {
      im.push_back(v + 1);
      im.push_back(v + 3);
      cr.push_back(v + 2);
    } else {
      if (x1) {
        im.push_back(v + 2);
        im.push_back(v + 3);
        cr.push_back(v + 1);
      } else {
        im.push_back(v + 1);
        im.push_back(v + 2);
        cr.push_back(v + 3);
      }
    }
  }
}

void deal2(vi& pos1, int zero, vi& im, vi& cr) {
  for (auto v : pos1) {
    int x1, x2;
    cout << "? " << zero << " " << v + 1 << " " << v + 2 << endl;
    cin >> x1;
    cout << "? " << zero << " " << v + 3 << " " << v + 2 << endl;
    cin >> x2;
    if (x1 + x2 == 0) {
      im.push_back(v + 2);
      cr.push_back(v + 1);
      cr.push_back(v + 3);
    } else if (x1 + x2 == 1) {
      if (x1) {
        im.push_back(v + 3);
        cr.push_back(v + 1);
        cr.push_back(v + 2);
      } else {
        im.push_back(v + 1);
        cr.push_back(v + 2);
        cr.push_back(v + 3);
      }
    } else {
      cr.push_back(v + 1);
      cr.push_back(v + 2);
      cr.push_back(v + 3);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi pos0, pos1;
    // split into n/3 groups and store one 0 group and one 1 group.
    int zero = 0, one = 0;
    for (int i = 0; i < n; i += 3) {
      cout << "? " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
      int r;
      cin >> r;
      if (r)
        one = i, pos1.push_back(i);
      else
        zero = i, pos0.push_back(i);
    }
    // choose one from one group and choose one from zero group, then check the
    // reamind four for each.
    int x, s = 0;
    cout << "? " << zero + 1 << " " << one + 1 << " " << zero + 2 << endl;
    cin >> x;
    s += x;
    cout << "? " << zero + 1 << " " << one + 1 << " " << zero + 3 << endl;
    cin >> x;
    s += x;
    cout << "? " << zero + 1 << " " << one + 1 << " " << one + 2 << endl;
    cin >> x;
    s += x;
    cout << "? " << zero + 1 << " " << one + 1 << " " << one + 3 << endl;
    cin >> x;
    s += x;
    if (s == 0) {
      zero = zero + 1;
      one = one + 2;
    } else if (s == 4) {
      zero = zero + 2;
      one = one + 1;
    } else {
      zero += 1;
      one += 1;
    }

    vi im, cr;
    cout << "? " << one << " " << zero << " " << pos0.back() + 3 << endl;
    cin >> x;
    if (x) {
      im.push_back(pos0.back() + 1), im.push_back(pos0.back() + 2);
      cr.push_back(pos0.back() + 3);
      pos0.pop_back();
      deal1(pos0, cr.back(), im, cr);
      deal2(pos1, im.back(), im, cr);
    } else {
      deal2(pos1, pos0.back() + 3, im, cr);
      deal1(pos0, cr.back(), im, cr);
    }
    cout << "! " << im.size();
    REP(i, 0, im.size()) cout << " " << im[i];
    cout << endl;
  }
  return 0;
}
