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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

template <typename T>
void read(T& x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

// struct

// data
int r, c;
char m[32][32];

void solve() {
  map<char, set<char>> pre;
  REP(i, 0, r - 1) {
    REP(j, 0, c) {
      if (m[i][j] == m[i + 1][j]) continue;
      if (pre.find(m[i][j]) == pre.end()) pre[m[i][j]] = {};
      pre[m[i][j]].insert(m[i + 1][j]);
    }
  }
  REP(j, 0, c) if (pre.find(m[r - 1][j]) == pre.end()) pre[m[r - 1][j]] = {};
  string ans;
  while (true) {
    bool f = false;
    for (auto it : pre) {
      if (it.second.empty()) {
        char cc = it.first;
        pre.erase(cc);
        ans += cc;
        for (auto& tit : pre) {
          tit.second.erase(cc);
        }
        f = true;
      }
    }
    if (!f) break;
  }
  if (pre.size())
    printf("-1\n");
  else
    printf("%s\n", ans.c_str());
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &r, &c);
    REP(i, 0, r) scanf("%s", m[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
