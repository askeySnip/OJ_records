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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  int t = __builtin_popcount(n);
  if (t <= k) {
    printf("0\n");
  } else {
    int ans = 0;
    int d = k;
    for (int i = 31; i >= 0; i--) {
      if (n & (1 << i)) {
          d--;
          n ^= (1 << i);
          if(d == 0) {
            ans = (1 << i) - n;
            break;
          }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
