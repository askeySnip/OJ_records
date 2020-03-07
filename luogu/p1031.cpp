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
int a[110];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  int s = 0;
  REP(i, 0, n) s += a[i];
  int avg = s / n;
  int ans = 0;
  int pre = 0, ep = 0;
  REP(i, 0, n) {
    pre += a[i];
    ep += avg;
    if (pre != ep) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
