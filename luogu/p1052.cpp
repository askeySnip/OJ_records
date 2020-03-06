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
int l, s, t, m;
int stn[110], sz[110], vist[300000], f[300000];

int main() {
  scanf("%d%d%d%d", &l, &s, &t, &m);
  REP(i, 1, m + 1) scanf("%d", &stn[i]);
  sort(stn + 1, stn + 1 + m);
  stn[0] = 0;

  REP(i, 1, m + 1) { sz[i] = (stn[i] - stn[i - 1]) % 2520; }
  REP(i, 1, m + 1) {
    stn[i] = stn[i - 1] + sz[i];
    vist[stn[i]] = 1;
  }
  l = stn[m];
  int ans = m;
  REP(i, 0, l + t + 1) f[i] = m;
  f[0] = 0;
  REP(i, 1, l + t + 1) {
    REP(j, s, t + 1) {
      if (i >= j) f[i] = min(f[i], f[i - j]);
      f[i] += vist[i];
    }
  }
  REP(i, l, l + t + 1) ans = min(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
