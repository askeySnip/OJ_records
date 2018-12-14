/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i<int(b); i++)
// data
int n;
int a[103];

int check(int x) {
  int ret = 0;
  REP(i, 0, n) {
    ret += a[i] * (abs(x-i)+ i + x) * 2;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  int ans = inf;
  REP(x, 0, n) {
    ans = min(ans, check(x));
  }
  printf("%d\n", ans);
  return 0;
}
