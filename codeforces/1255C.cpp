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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, m;
ii a[1024];

void solve() {
  if (m < n || n == 2) {
    printf("-1\n");
    return;
  } else if (m == n) {
    int s = 0;
    REP(i, 0, n) s += 2 * a[i].first;
    printf("%d\n", s);
    REP(i, 0, m) { printf("%d %d\n", a[i].second, a[(i + 1) % n].second); }
  } else {
    if (n == 3) {
      int s = 2 * (a[0].first + a[1].first + a[2].first);
      sort(a, a + n);
      REP(i, n, m) { s += a[0].first + a[1].first; }
      printf("%d\n", s);
      REP(i, 0, n) { printf("%d %d\n", a[i].second, a[(i + 1) % n].second); }
      int id1 = a[0].second;
      int id2 = a[1].second;
      REP(i, n, m) { printf("%d %d\n", id1, id2); }
    } else if (n == 4) {
      int s = 0;
      for (int i = 0; i < 4; i++) s += 2 * a[i].first;
      sort(a, a + n);
      s += a[0].first + a[1].first;
      for (int i = 5; i < m; i++) {
        s += a[0].first + a[1].first;
      }
      printf("%d\n", s);
      printf("%d %d\n", a[2].second, a[0].second);
      printf("%d %d\n", a[0].second, a[1].second);
      printf("%d %d\n", a[1].second, a[3].second);
      printf("%d %d\n", a[2].second, a[1].second);
      printf("%d %d\n", a[0].second, a[3].second);
      int id1 = a[0].second;
      int id2 = a[1].second;
      for (int i = 5; i < m; i++) {
        printf("%d %d\n", id1, id2);
      }
    } else {
      int s = 0;
      REP(i, 0, n) s += 2 * a[i].first;
      sort(a, a + n);
      s += a[0].first * 2;
      for (int i = n + 1; i < m; i++) {
        s += a[0].first + a[1].first;
      }
      printf("%d\n", s);
      REP(i, 0, n - 1) {
        printf("%d %d\n", a[(i + n / 2 + 1) % n].second,
               a[(i + 1 + n / 2 + 1) % n].second);
      }
      printf("%d %d\n", a[(n / 2 + 1) % n].second, a[0].second);
      printf("%d %d\n", a[(n - 1 + n / 2 + 1) % n].second, a[0].second);
      REP(i, n, m) { printf("%d %d\n", a[0].second, a[1].second); }
    }
  }
}

int main() {
  int k, kase = 0;
  scanf("%d", &k);
  // k = 1;
  while (k--) {
    scanf("%d%d", &n, &m);
    REP(i, 0, n) a[i].second = i + 1;
    REP(i, 0, n) scanf("%d", &a[i].first);
    solve();
  }

  return 0;
}