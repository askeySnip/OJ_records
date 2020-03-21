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
#define LS(a) (a << 1)
#define RS(a) (a << 1 | 1)

// struct

// data
int n, p, m;
int a[100024];

ll sg[4 * 100024];
ll lazy[4 * 100024], mul[4 * 100024];

void up(int v) { sg[v] = (sg[LS(v)] + sg[RS(v)]) % p; }

void build(int v, int l, int r) {
  mul[v] = 1;
  if (l == r) {
    sg[v] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(LS(v), l, mid);
  build(RS(v), mid + 1, r);
  up(v);
}

void pd(int v, int s, int t) {
  int l = LS(v), r = RS(v), mid = (s + t) >> 1;
  if (mul[v] != 1) {
    mul[l] *= mul[v];
    mul[l] %= p;
    mul[r] *= mul[v];
    mul[r] %= p;
    lazy[l] *= mul[v];
    lazy[l] %= p;
    lazy[r] *= mul[v];
    lazy[r] %= p;
    sg[l] *= mul[v];
    sg[l] %= p;
    sg[r] *= mul[v];
    sg[r] %= p;
    mul[v] = 1;
  }
  if (lazy[v]) {
    sg[l] += lazy[v] * (mid - s + 1);
    sg[r] += lazy[v] * (t - mid);
    lazy[l] += lazy[v];
    lazy[r] += lazy[v];
    lazy[l] %= p;
    lazy[r] %= p;
    sg[l] %= p;
    sg[r] %= p;
    lazy[v] = 0;
  }
}

void multi(int v, int tl, int tr, int l, int r, int c) {
  if (l > r) return;
  if (tl == l && tr == r) {
    mul[v] *= c;
    lazy[v] *= c;
    sg[v] *= c;
    mul[v] %= p;
    lazy[v] %= p;
    sg[v] %= p;
    return;
  }
  pd(v, tl, tr);
  int mid = (tl + tr) >> 1;
  multi(LS(v), tl, mid, l, min(r, mid), c);
  multi(RS(v), mid + 1, tr, max(mid + 1, l), r, c);
  up(v);
}

void add(int v, int tl, int tr, int l, int r, int c) {
  if (l > r) return;
  if (l == tl && r == tr) {
    lazy[v] += c;
    sg[v] += c * (r - l + 1);
    lazy[v] %= p;
    sg[v] %= p;
    return;
  }
  pd(v, tl, tr);
  int mid = (tl + tr) >> 1;
  add(LS(v), tl, mid, l, min(r, mid), c);
  add(RS(v), mid + 1, tr, max(l, mid + 1), r, c);
  up(v);
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return sg[v];
  }
  pd(v, tl, tr);
  int mid = (tl + tr) >> 1;
  return (query(LS(v), tl, mid, l, min(r, mid)) +
         query(RS(v), mid + 1, tr, max(l, mid + 1), r)) % p;
}

int main() {
  scanf("%d%d", &n, &p);
  REP(i, 1, n + 1) scanf("%d", &a[i]);
  build(1, 1, n);
  scanf("%d", &m);
  int tp, t, g, c;
  REP(i, 0, m) {
    scanf("%d", &tp);
    if (tp != 3) {
      scanf("%d%d%d", &t, &g, &c);
      if (tp == 1) {
        multi(1, 1, n, t, g, c);
      } else {
        add(1, 1, n, t, g, c);
      }
    } else {
      scanf("%d%d", &t, &g);
      printf("%lld\n", query(1, 1, n, t, g));
    }
  }
  return 0;
}
