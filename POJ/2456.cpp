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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)

// data
const int inf = 1e9+1000;
int n, c;
int x[100024];

bool check(int t) {
  int last = 0;
  REP(i, 1, c) {
    int crt = last + 1;
    while(crt < n && x[crt] - x[last] < t) crt++;
    if(crt == n) return false;
    last = crt;
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &c);
  REP(i, 0, n) {
    scanf("%d", &x[i]);
  }
  sort(x, x+n);
  int l = 0, h = inf, mid;
  while(l + 1 < h) {
    mid = (l + h) / 2;
    if(check(mid)) l = mid;
    else h = mid;
  }
  printf("%d\n", l);
  return 0;
}
