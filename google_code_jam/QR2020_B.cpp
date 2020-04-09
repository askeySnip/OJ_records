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

char s[110];
int l, ans_l;
char ans[1024];

void dfs(int l, int r, char split) {
  while (l <= r && s[l] == split) {
    ans[ans_l++] = split;
    l++;
  }
  int rr = r;
  while (l <= r && s[r] == split) r--;
  int last = l;
  for (int i = l; i <= r;) {
    if (s[i] == split) {
      if (last <= i - 1) {
        ans[ans_l++] = '(';
        dfs(last, i - 1, split + 1);
        ans[ans_l++] = ')';
      }
      while (i <= r && s[i] == split) {
        ans[ans_l++] = split;
        i++;
      }
      last = i;
    } else {
      i++;
    }
  }
  if(last <= r) {
    ans[ans_l++] = '(';
    dfs(last, r, split + 1);
    ans[ans_l++] = ')';
  }
  for (int i = r + 1; i <= rr; i++) ans[ans_l++] = split;
}

void solve() {
  ans_l = 0;
  l = strlen(s);
  dfs(0, l - 1, '0');
  ans[ans_l] = '\0';
  printf("%s\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%s", s);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
