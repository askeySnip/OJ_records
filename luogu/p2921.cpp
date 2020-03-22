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
int nxt[100024], in[100024], ans[100024];
bool vist[100024];

void del(int i) {
  vist[i] = 1;
  in[nxt[i]]--;
  if (!in[nxt[i]]) del(nxt[i]);
}

int cac_circle(int u, int d) {
  ans[u] = d;
  if (ans[nxt[u]])
    return d;
  else
    return ans[u] = cac_circle(nxt[u], d + 1);
}

int cac(int u) {
  if (ans[u]) return ans[u];
  return ans[u] = cac(nxt[u]) + 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", nxt + i), in[nxt[i]]++;
  for (int i = 1; i <= n; i++)
    if (!in[i] && !vist[i]) del(i);
  for (int i = 1; i <= n; i++)
    if (in[i] && !ans[i]) cac_circle(i, 1);
  for (int i = 1; i <= n; i++)
    if (!ans[i]) cac(i);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
