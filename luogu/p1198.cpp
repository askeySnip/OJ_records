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
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int m, d;

int sg[4 * 200010];
void update(int v, int l, int r, int pos, int nv) {
  if (l == r) {
    sg[v] = nv;
    return;
  }
  int mid = (l + r) / 2;
  if (pos > mid) {
    update(v * 2 + 1, mid + 1, r, pos, nv);
  } else {
    update(v * 2, l, mid, pos, nv);
  }
  sg[v] = max(sg[v * 2], sg[v * 2 + 1]);
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return sg[v];
  }
  int mid = (tl + tr) / 2;
  return max(query(v * 2, tl, mid, l, min(r, mid)),
             query(v * 2 + 1, mid + 1, tr, max(mid + 1, l), r));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  memset(sg, 0, sizeof sg);
  cin >> m >> d;
  char c;
  ll val;
  int t = 0;
  int cnt = 0;
  REP(i, 0, m) {
    cin >> c >> val;
    if (c == 'A') {
      val = (val + t) % d;
      update(1, 0, m - 1, cnt, val);
      cnt++;
    } else {
      t = query(1, 0, m - 1, cnt - val, cnt - 1);
      cout << t << "\n";
    }
  }
  return 0;
}
