/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return x * w;
}

// struct
class BIT {
 private:
  vi ft;

 public:
  BIT(int n) { ft.assign(n + 1, 0); }
  void add(int p, int v) {
    for (; p < ft.size(); p += p & (-p)) {
      ft[p] += v;
    }
  }
  int sum(int p) {
    int ans = 0;
    for (; p; p -= p & (-p)) {
      ans += ft[p];
    }
    return ans;
  }
  int range(int l, int r) { return sum(r) - sum(l - 1); }
};

// data
int n, m;
int a[1000024];
int a_pos[1000024];
vector<tuple<int, int, int>> query;

int main() {
  n = read();
  REP(i, 1, n + 1) a[i] = read();
  m = read();
  int l, r;
  query.resize(m);
  REP(i, 0, m) {
    l = read(), r = read();
    query[i] = {r, l, i};
  }
  sort(query.begin(), query.end());
  vi ans(m);
  BIT bit(n);
  int pos = 1;
  REP(i, 0, m) {
    int id;
    tie(r, l, id) = query[i];
    while (pos <= r) {
      if (a_pos[a[pos]] == 0) {
        bit.add(pos, 1);
        a_pos[a[pos]] = pos;
      } else {
        bit.add(pos, 1);
        bit.add(a_pos[a[pos]], -1);
        a_pos[a[pos]] = pos;
      }
      pos++;
    }
    ans[id] = bit.range(l, r);
  }
  REP(i, 0, m) printf("%d\n", ans[i]);
  return 0;
}
