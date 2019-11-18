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
const int inf = 1e9;
const int mod = 1e9 + 7;

int n;
char g[110][110];

void solve() {
  int c1sz = 0, c2sz = 0;
  vector<char> c1[110], c2[110];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        c1[(i + j) / 2].push_back(g[i][j]);
        c1sz = max(c1sz, (i + j) / 2);
      }
    }
  }
  int cnt1 = 0, cnt2 = 1;
  for (int i = 0; i <= c1sz; i++) {
    int sz = c1[i].size();
    char t = c1[i][sz / 2];
    if (t == '.')
      cnt1++;
    else
      cnt2++;
  }
  int c1midsz = c1[n / 2].size();
  for (int i = 0; i < c1midsz; i++) {
    if (i == c1midsz / 2) continue;
    if (c1[n / 2][i] != c1[n / 2][c1midsz / 2])
      cnt1++;
    else
      cnt2++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 1) {
        c2[(i + j) / 2].push_back(g[i][j]);
        c2sz = max(c2sz, (i + j) / 2);
      }
    }
  }
  int cnt3 = 0, cnt4 = 1;
  for (int i = 0; i <= c2sz; i++) {
    int sz = c2[i].size();
    char t = c2[i][sz / 2];
    if (t == '.')
      cnt3++;
    else
      cnt4++;
  }
  int c2midsz = c2[c2sz / 2].size();
  for (int i = 0; i < c2midsz; i++) {
    if (i == c2midsz / 2) continue;
    if (c2[c2sz / 2][i] != c2[c2sz / 2][c2midsz / 2])
      cnt3++;
    else
      cnt4++;
  }
  printf("%d\n", min(cnt1, cnt2) + min(cnt3, cnt4));
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%s", g[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
