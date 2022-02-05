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

vector<int> GetEndPoint(string order) {
  // write code here
  int x = 0, y = 0;
  int cur = 0, n = order.length(), flag = 1;
  for (int i = 0; i < n; i++) {
    if (order[i] == '-') flag = -1, ++cur;
    if ((order[i] >= 'A' && order[i] <= 'Z') || (order[i] >= 'a' || order[i] <= 'z')) {
      int l = (i == cur ? 1 : stoi(order.substr(cur, i - cur)));
      l *= flag;
      if (order[i] == 'W' || order[i] =='w')
        y += l;
      else if (order[i] == 'S' || order[i] == 's')
        y -= l;
      else if (order[i] == 'A' || order[i] == 'a')
        x -= l;
      else if (order[i] == 'D' || order[i] == 'd')
        x += l;
      cur = i + 1;
      flag = 1;
    }
  }
  return {x, y};
}

int main() {
  auto p = GetEndPoint("-AWSD");
  cout << p[0] << " " << p[1] << endl;
  return 0;
}
