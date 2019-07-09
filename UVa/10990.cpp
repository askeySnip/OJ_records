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
int m[2000024];

void modified_sieve() {
  REP(i, 1, 2000001) m[i] = i;
  REP(i, 2, 2000001) {
    if(m[i] == i) {
      for(int j=i; j<2000001; j+=i) {
        m[j] = m[j] - m[j]/i;
      }
    }
  }
}

int main() {
  modified_sieve();
  int dpth[2000001];
  memset(dpth, 0, sizeof dpth);
  dpth[2] = 1;
  REP(i, 2, 2000001) {
    dpth[i] = dpth[m[i]] + 1;
  }
  REP(i, 2, 2000001) {
    dpth[i] += dpth[i-1];
  }

  int n, a, b;
  scanf("%d", &n);
  while(n--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", dpth[b] - dpth[a-1]);
  }
  return 0;
}
