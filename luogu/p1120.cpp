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
#include <numeric>
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
int n, tot, len;
vi a;
vi used, nxt;
bool ok;

void dfs(int m, int last, int rem) {
  if (!rem) {
    if (!m) {
      ok = 1;
      return;
    }
    REP(i, 0, a.size()) {
      if (!used[i]) {
        used[i] = 1;
        dfs(m - 1, i, len - a[i]);
        used[i] = 0;
        return;
      }
    }
  }
  int p = last + 1;
  while (p < a.size() && a[p] > rem) p++;
  for (; p < a.size(); p = nxt[p]) {
    while (p < a.size() && used[p]) p++;
    if (p == a.size()) return;
    used[p] = 1;
    dfs(m, p, rem - a[p]);
    used[p] = 0;
    if (ok) return;
    if (rem == a[p] || rem == len) return;
  }
}

int main() {
  scanf("%d", &n);
  int l;
  a.clear();
  REP(i, 0, n) {
    scanf("%d", &l);
    if (l <= 50) a.push_back(l);
  }
  used.assign(a.size(), 0);
  nxt.resize(a.size());
  sort(a.begin(), a.end(), greater<int>());
  nxt.back() = a.size();
  for (int i = a.size() - 2; i >= 0; i--) {
    if (a[i] == a[i + 1])
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = i + 1;
  }
  tot = accumulate(a.begin(), a.end(), 0);
  for (int i = a[0]; i <= tot / 2; i++) {
    if (tot % i) continue;
    ok = 0;
    used[0] = 1;
    len = i;
    dfs(tot / i - 1, 0, i - a[0]);
    used[0] = 0;
    if (ok) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("%d\n", tot);
  return 0;
}
