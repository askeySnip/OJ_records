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
int a, b, n;
int m[1024][1024];
int row_max[1024][1024], row_min[1024][1024];
int v_max[1024][1024], v_min[1024][1024];

struct min_queue {
  deque<ii> dq;
  int w;
  min_queue(int w_) { w = w_; }
  int insert(int p, int v) {
    while (!dq.empty() && dq.back().second >= v) dq.pop_back();
    dq.push_back(ii(p, v));
    if (dq.front().first + w <= p) dq.pop_front();
    return dq.front().second;
  }
};

int main() {
  scanf("%d%d%d", &a, &b, &n);
  REP(i, 0, a) {
    REP(j, 0, b) { scanf("%d", &m[i][j]); }
  }
  REP(i, 0, a) {
    min_queue mq1(n), mq2(n);
    REP(j, 0, b) {
      row_min[i][j] = mq1.insert(j, m[i][j]);
      row_max[i][j] = -mq2.insert(j, -m[i][j]);
    }
  }
  REP(j, 0, b) {
    min_queue mq1(n), mq2(n);
    REP(i, 0, a) {
      v_min[i][j] = mq1.insert(i, row_min[i][j]);
      v_max[i][j] = -mq2.insert(i, -row_max[i][j]);
    }
  }
  int ans = inf;
  REP(i, n-1, a) {
    REP(j, n-1, b) {
      ans = min(ans, v_max[i][j] - v_min[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
