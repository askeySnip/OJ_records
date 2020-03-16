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
int n, m;
int minl[200024], maxr[200024];
int f[200024];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + 1; i++) minl[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    minl[y] = min(minl[y], x);
    maxr[y + 1] = max(maxr[y + 1], x);
  }
  for (int i = n; i >= 1; i--) minl[i] = min(minl[i], minl[i + 1]);
  for (int i = 1; i <= n + 1; i++) maxr[i] = max(maxr[i], maxr[i - 1]);
  int j = 1;
  deque<int> dq;
  dq.push_back(0);
  for (int i = 1; i <= n + 1; i++) {
    for (; j < minl[i]; j++) {
      if (f[j] != -1) {
        while (!dq.empty() && f[dq.back()] <= f[j]) dq.pop_back();
        dq.push_back(j);
      }
    }
    while (!dq.empty() && dq.front() < maxr[i]) dq.pop_front();
    if (dq.empty())
      f[i] = -1;
    else
      f[i] = f[dq.front()] + (i != n + 1);
  }
  printf("%d\n", f[n + 1]);
  return 0;
}
