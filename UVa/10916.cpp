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
double mem[1<<23];

int main() {
  int y;
  memset(mem, 0, sizeof mem);
  mem[1] = 0;
  REP(i, 2, 1<<23) {
    mem[i] = mem[i-1] + log2(i);
  }
  while(scanf("%d", &y), y) {
    int x = 4 * (1 << ((y-1960)/10));
    int t = upper_bound(mem+1, mem+(1<<23), x) - (mem+1);
    printf("%d\n", t);
  }
  return 0;
}
