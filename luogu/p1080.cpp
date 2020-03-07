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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n;
ii ab[1024];
int s[4030], len;
int ans[4030], len_a;

void Multi(int x) {
  REP(i, 0, len) s[i] *= x;
  int t = 0;
  for (int i = 0; i < len + 5; i++) {
    if (s[i]) t = i+1;
    s[i + 1] += s[i] / 10;
    s[i] = s[i] % 10;
  }
  len = t;
}

void Div(int x) {
  int ts[4030], l(-1);
  REP(i, 0, len) ts[i] = s[i];
  for (int i = len - 1; i >= 0; i--) {
    if(i) ts[i - 1] += (ts[i] % x) * 10;
    ts[i] /= x;
    if (ts[i] && l == -1) l = i + 1;
  }
  if (len_a == l) {
    bool f = false;
    for (int i = l - 1; i >= 0; i--) {
      if (ans[i] < ts[i]) {
        f = true;
        break;
      }
      if (ans[i] > ts[i]) break;
    }
    if (f) {
      REP(i, 0, l) ans[i] = ts[i];
    }
  }
  if (len_a < l) {
    REP(i, 0, l) ans[i] = ts[i];
    len_a = l;
  }
}

int main() {
  scanf("%d", &n);
  scanf("%d%d", &ab[0].first, &ab[0].second);
  REP(i, 1, n + 1) scanf("%d%d", &ab[i].first, &ab[i].second);
  sort(ab + 1, ab + 1 + n, [](ii a, ii b) {
    return 1LL * a.first * a.second < 1LL * b.first * b.second;
  });
  memset(ans, 0, sizeof ans);
  memset(s, 0, sizeof s);
  s[0] = 1;
  len = 1;
  len_a = 0;
  REP(i, 1, n + 1) {
    Multi(ab[i - 1].first);
    Div(ab[i].second);
  }
  for (int i = len_a - 1; i >= 0; i--) {
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
