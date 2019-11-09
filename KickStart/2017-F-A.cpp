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
int n;
int a[10003];
bool f;

// notice the sequence...
void Kicksort(int s, int e) {
  if (e - s <= 1) return;
  int mid = (e + s - 1) / 2;
  if (a[mid] != s + 1 && a[mid] != e) f = true;
  if (f) return;
  int front = s, tail = e - 1, pivot = a[mid];
  vi tmp;
  int cnt = 0;
  REP(i, s, e) {
    if (i == mid) continue;
    tmp.push_back(a[i]);
    if (a[i] > pivot) cnt++;
  }
  tail = e - cnt;
  REP(i, 0, tmp.size()) {
    if (tmp[i] <= pivot)
      a[front++] = tmp[i];
    else
      a[tail++] = tmp[i];
  }
  a[front] = pivot;
  Kicksort(s, front);
  Kicksort(front + 1, e);
}

void solve() {
  f = false;
  Kicksort(0, n);
  if (f)
    printf("NO\n");
  else
    printf("YES\n");
}

int main() {
  // freopen("KickStart/large.in", "r", stdin);
  // freopen("KickStart/large.out", "w", stdout);
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }

  return 0;
}
