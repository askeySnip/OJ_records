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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int a[1024];
int n;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

int solve() {
  int last = a[1];
  REP(i, 2, n) {
    last = gcd(last, a[i]);
  }
  return last>0? last:-last;    // notice: must return a positive number.
}

int main() {
  while(scanf("%d", &a[0]), a[0]) {
    n = 1;
    while(scanf("%d", &a[n++]), a[n-1]);
    n--;
    REP(i, 1, n) a[i] -= a[0];
    printf("%d\n", solve());
  }
  return 0;
}
