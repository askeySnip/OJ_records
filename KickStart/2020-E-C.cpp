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
struct cmp {
  bool operator()(const ii a, const ii b) { return a.first < b.first; }
};

// data
int n;
int e[100010], r[100010];

void solve() {
  ll sum = 0;
  REP(i, 0, n) sum += e[i];
  ll ans = sum, del = 0;
  ll cur_time = sum, dd = 0;
  priority_queue<ii, vii, cmp> pq;
  REP(i, 0, n) {
    cur_time += e[i];
    pq.push({e[i] + r[i], i});
    while (!pq.empty() && pq.top().first > sum) {
      sum -= e[pq.top().second];
      cur_time -= e[pq.top().second] * 2;
      pq.pop();
      ++dd;
    }
    if (cur_time > ans) {
      ans = cur_time;
      del = dd;
    }
  }
  if (!pq.empty()) {
    printf("%lld INDEFINITELY\n", dd);
  } else {
    printf("%lld %lld\n", del, ans);
  }
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n)
    scanf("%d%d", &e[i], &r[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
