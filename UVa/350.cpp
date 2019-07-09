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
int z, i, m, l;

inline int f(int x) {
  return (z*x+i)%m;
}

int main() {
  int kase = 0;
  while(scanf("%d %d %d %d", &z, &i, &m, &l), z || i || m || l) {
    int t = l, h = l;
    int len, u;
    t = f(t); h = f(f(h));
    while(t != h) {
      t = f(t);
      h = f(f(h));
    }
    h = l;
    u = 0;
    while(h != t) {
      t = f(t);
      h = f(h);
      u++;
    }
    h = f(t);
    len = 1;
    while(h != t) {
      h = f(h);
      len++;
    }
    printf("Case %d: %d\n", ++kase, len);
  }
  return 0;
}
