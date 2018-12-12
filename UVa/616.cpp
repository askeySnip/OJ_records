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
int n;

bool check(int p) {
  int t = n;
  REP(i, 0, p) {
    if(t%p != 1) return false;
    t = t - t/p - 1;
  }
  return (t%p == 0);
}

int main() {
  while(scanf("%d", &n), n >= 0) {
    bool flag = false;
    int s = sqrt(n)+1, i;
    for(i=s; i>=1; i--) {
      if(check(i)) {
        flag = true;
        break;
      }
    }
    if(flag) printf("%d coconuts, %d people and 1 monkey\n", n, i);
    else printf("%d coconuts, no solution\n", n);
  }
  return 0;
}
