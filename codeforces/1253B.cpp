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
int n;
int a[100010];

void solve() {
  set<int> s;
  set<int> vist;
  int day = 0;
  vi c;
  int start = 0;
  REP(i, 0, n) {
    if (a[i] > 0) {
      if (!s.empty()) {
        if (s.count(a[i]) || vist.count(a[i])) {
          printf("-1\n");
          return;
        } else {
          vist.insert(a[i]);
          s.insert(a[i]);
        }
      } else {
        start = i;
        vist.insert(a[i]);
        s.insert(a[i]);
      }
    } else {
      if (s.empty()) {
        printf("-1\n");
        return;
      } else {
        if (s.count(-a[i]) == 0) {
          printf("-1\n");
          return;
        } else {
          s.erase(-a[i]);
          if (s.empty()) {
            day++;
            c.push_back(i - start + 1);
            vist.clear();
          }
        }
      }
    }
  }
  if (!s.empty()) {
    printf("-1\n");
    return;
  }
  printf("%d\n", day);
  REP(i, 0, day) {
    if (i) printf(" ");
    printf("%d", c[i]);
  }
  printf("\n");
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    solve();
  }
  return 0;
}