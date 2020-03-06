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
#include <unordered_map>
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
int a[360];
unordered_map<int, int> mem;

int dp(int p, int x, int y, int z, int q) {
  if (p == n - 1) return a[p];
  int v = x + y * 40 + z * 1600 + q * 64000;
  if (mem.find(v) != mem.end()) return mem[v];
  int ret = 0;
  if (x) ret = max(dp(p + 1, x - 1, y, z, q), ret);
  if (y) ret = max(dp(p + 2, x, y - 1, z, q), ret);
  if (z) ret = max(dp(p + 3, x, y, z - 1, q), ret);
  if (q) ret = max(dp(p + 4, x, y, z, q - 1), ret);
  return mem[v] = ret + a[p];
}

int main() {
  scanf("%d%d", &n, &m);
  int b;
  int cnt[5]{0};
  REP(i, 0, n) scanf("%d", &a[i]);
  REP(i, 0, m) scanf("%d", &b), cnt[b]++;
  printf("%d\n", dp(0, cnt[1], cnt[2], cnt[3], cnt[4]));
  return 0;
}
