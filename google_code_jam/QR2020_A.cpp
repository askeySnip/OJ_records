/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
int m[110][110];

bool check1(int r) {
  set<int> s;
  REP(i, 0, n) {
    if (s.count(m[r][i])) return true;
    s.insert(m[r][i]);
  }
  return false;
}

bool check2(int c) {
  set<int> s;
  REP(i, 0, n) {
    if (s.count(m[i][c])) return true;
    s.insert(m[i][c]);
  }
  return false;
}

void solve() {
  int k = 0;
  REP(i, 0, n) k += m[i][i];
  int r = 0, c = 0;
  REP(i, 0, n) {
    if (check1(i)) r++;
  }
  REP(i, 0, n) {
    if (check2(i)) c++;
  }
  printf("%d %d %d\n", k, r, c);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) {
      REP(j, 0, n) { scanf("%d", &m[i][j]); }
    }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
