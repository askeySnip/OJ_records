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
const int mod = 100003;

// struct

// data
int n, m;
vi adj[1000024];
int dep[1000024], vist[1000024], cnt[1000024];

int main() {
  scanf("%d%d", &n, &m);
  int u, v, w;
  REP(i, 0, m) {
    scanf("%d%d", &u, &v);
    if (u != v) adj[u].push_back(v), adj[v].push_back(u);
  }
  queue<int> q;
  q.push(1);
  dep[1] = 1, vist[1] = 1, cnt[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (!vist[v]) {
        dep[v] = dep[u] + 1;
        vist[v] = 1;
        q.push(v);
      }
      if (dep[v] == dep[u] + 1) cnt[v] = (cnt[v] + cnt[u]) % mod;
    }
  }
  REP(i, 1, n + 1) printf("%d\n", cnt[i]);
  return 0;
}
