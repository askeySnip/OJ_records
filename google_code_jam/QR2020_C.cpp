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
ii se[1024];
char ans[1024];

bool cmp(int a, int b) {
  if (se[a].first == se[b].first) return se[a].second < se[b].second;
  return se[a].first < se[b].first;
}

void solve() {
  vi order(n);
  REP(i, 0, n) order[i] = i;
  sort(order.begin(), order.end(), cmp);
  ii a{0, -1}, b{1, -1};
  REP(i, 0, n) {
    if (a.second > se[order[i]].first) {
      printf("IMPOSSIBLE\n");
      return;
    }
    if (b.second <= se[order[i]].first) {
      ans[order[i]] = b.first ? 'J' : 'C';
      b.second = se[order[i]].second;
      if (b.second < a.second) swap(a, b);
      continue;
    }
    ans[order[i]] = a.first ? 'J' : 'C';
    a.second = se[order[i]].second;
    if (b.second < a.second) swap(a, b);
  }
  ans[n] = '\0';
  printf("%s\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d%d", &se[i].first, &se[i].second);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
