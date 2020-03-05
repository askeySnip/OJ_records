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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, k;
ii pt[10024];
int mem[10024];

int dp(int s) {
  if (s >= n) return 0;
  if (mem[s] != -1) return mem[s];
  int ret = 0;
  int idx = lower_bound(pt, pt + k, ii(s, 0)) - pt;
  if (idx == k) return n - s + 1;
  int i = idx;
  while (pt[i].first == pt[idx].first) {
    ret = max(ret, pt[i].first - s + dp(pt[i].first + pt[i].second));
    i++;
  }
  return mem[s] = ret;
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, 0, k) scanf("%d%d", &pt[i].first, &pt[i].second);
  sort(pt, pt + k);
  memset(mem, -1, sizeof mem);
  printf("%d\n", dp(1));
  return 0;
}
