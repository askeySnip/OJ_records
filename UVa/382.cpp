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
  printf("PERFECTION OUTPUT\n"); // notice the special case: n = 1, DEFICIENT
  while(scanf("%d", &n), n) {
    int ans = 0, i;
    for(i=2; i * i < n; i++) {
      if(n % i == 0) {
        ans += i;
        ans += n/i;
      }
    }
    if(n != 1 && i * i == n) ans += i;
    if(n != 1) ans += 1;
    printf("%5d  ", n);
    if(ans == n) printf("PERFECT\n");
    else if (ans < n) printf("DEFICIENT\n");
    else printf("ABUNDANT\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
