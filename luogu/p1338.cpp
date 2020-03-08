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
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  vi ans(n + 1);
  REP(i, 0, n + 1) ans[i] = i;
  int s = 1;
  int cnt = 1;
  while (s < m) {
    cnt++;
    s += cnt;
  }
  if (s == m) {
    reverse(ans.rbegin(), ans.rbegin() + cnt + 1);
  } else {
    reverse(ans.rbegin(), ans.rbegin() + cnt);
    int p = n, cns_p = n - cnt;
    s -= cnt;
    while (s < m) {
      swap(ans[p--], ans[cns_p]);
      s++;
    }
  }
  REP(i, 1, n) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}
