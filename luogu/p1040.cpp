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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n;
ll f[33][33];
int root[33][33];
vi path;

ll dp(int l, int r) {
  if (l > r) return 1;
  if (f[l][r] == -1) {
    REP(i, l, r + 1) {
      ll t = dp(l, i - 1) * dp(i + 1, r) + f[i][i];
      if (t > f[l][r]) {
        f[l][r] = t;
        root[l][r] = i;
      }
    }
  }
  return f[l][r];
}

void preorder(int l, int r) {
  if (l > r) return;
  path.push_back(root[l][r]);
  preorder(l, root[l][r] - 1);
  preorder(root[l][r] + 1, r);
}

void solve() {
  printf("%lld\n", dp(1, n));
  preorder(1, n);
  REP(i, 0, n) {
    if (i) printf(" ");
    printf("%d", path[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  memset(f, -1, sizeof f);
  path.clear();
  REP(i, 1, n + 1) {
    scanf("%lld", &f[i][i]);
    root[i][i] = i;
  }
  solve();
  return 0;
}
