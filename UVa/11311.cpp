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

// Nim game to view the topping left, right, above, below to four heap;
int main() {
  int t, m, n, r, c;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d %d", &m, &n, &r, &c);
    int lh, ah, bh, rh;
    lh = c;
    ah = r;
    bh = (m - r - 1);
    rh = (n - c - 1) * m;
    if(lh ^ ah ^ bh ^ rh) printf("Gretel\n");
    else printf("Hansel\n");
  }
  return 0;
}
