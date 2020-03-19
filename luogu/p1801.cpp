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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int m, n;
int a[200024], u[200024];
priority_queue<int> max_pq;
priority_queue<int, vi, greater<int>> min_pq;
void insert(int v) {
  if (!max_pq.empty() && max_pq.top() > v) {
    max_pq.push(v);
    min_pq.push(max_pq.top());
    max_pq.pop();
  } else {
    min_pq.push(v);
  }
}

int main() {
  scanf("%d%d\n", &m, &n);
  REP(i, 1, m + 1) { scanf("%d", &a[i]); }
  REP(i, 1, n + 1) { scanf("%d", &u[i]); }
  int ui = 1;
  REP(i, 1, m + 1) {
    insert(a[i]);
    while (ui <= n && u[ui] == i) {
      printf("%d\n", min_pq.top());
      max_pq.push(min_pq.top());
      min_pq.pop();
      ui++;
    }
  }
  return 0;
}
