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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data


int main() {
  int t, n, k;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &k);
    bool win = true;
    if(k % 3) {
      if(n % 3 == 0) win = false;
    } else {
      int x = k / 3 - 1;
      x = x * 3 + 4;
      x = n % x;
      if(x % 3 == 0 && x != k) win = false;
    }
    if(win) printf("Alice\n");
    else printf("Bob\n");
  }
  return 0;
}
