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
int n;

int f[1024], b[1024], o[1024], d[1024];
bool cmp(int x, int y) { return d[x] > d[y]; }

int main() {
  scanf("%d", &n);
  b[1] = 1, o[1] = o[0] = n;
  REP(i, 2, n + 1) {
    scanf("%d", &f[i]);
    b[i] = i;
    o[i] = n;
    d[i] = d[f[i]] + 1;
  }
  sort(b + 1, b + 1 + n, cmp);
  int ans = 0;
  REP(i, 1, n + 1) {
    int u = b[i], v = f[u], w = f[v];
    o[u] = min(o[u], min(o[v] + 1, o[w] + 2));
    if (o[u] > 2) {
      ans++;
      o[w] = 0;
      o[f[w]] = min(o[f[w]], 1);
      o[f[f[w]]] = min(o[f[f[w]]], 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
