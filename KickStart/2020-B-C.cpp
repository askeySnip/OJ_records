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
typedef vector<long long> vi;
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
char op[2300];
map<char, int> idx{{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};

vi get_cnt(int l, int r) {
  vi cnt(4, 0);
  int i = l;
  while (i <= r) {
    if (isdigit(op[i])) {
      int s = op[i] - '0';
      i += 2;
      int ti = i;
      int c = 1;
      while (c) {
        if (op[i] == '(') c++;
        if (op[i] == ')') c--;
        ++i;
      }
      vi tcnt = get_cnt(ti, i - 2);
      REP(i, 0, 4) cnt[i] += tcnt[i] * s;
    } else {
      cnt[idx[op[i]]]++;
      ++i;
    }
  }
  REP(i, 0, 4) cnt[i] %= (int)1e9;
  return cnt;
}

void solve() {
  n = strlen(op);
  vi cnt = get_cnt(0, n - 1);
  ll e = cnt[2] - cnt[3], s = cnt[1] - cnt[0];
  ll w = ((int)1e9 + e) % (int)1e9;
  ll h = ((int)1e9 + s) % (int)1e9;
  printf("%d %d\n", w + 1, h + 1);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%s", op);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
