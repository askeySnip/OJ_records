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


int main() {
  int n;
  while(scanf("%d", &n), n) {
    int t = 1, sum = 0;;
    vi bn;
    REP(i, 0, 31) {
      bn.push_back(n&1);
      sum += (n&1);
      n = n >> 1;
      if(t > n) break;
    }
    printf("The parity of ");
    for(int i=bn.size()-1; i>=0; i--) {
      printf("%d", bn[i]);
    }
    printf(" is %d (mod 2).\n", sum);
  }
  return 0;
}
