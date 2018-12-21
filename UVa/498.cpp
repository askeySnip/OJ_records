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
  int a;
  while(scanf("%d", &a) == 1) {
    vi c;
    c.push_back(a);
    char ch = getchar();
    if(ch != '\n'){
      while(scanf("%d", &a)) {
        c.push_back(a);
        ch = getchar();
        if(ch == '\n') break;
      }
    }
    int n = c.size();
    reverse(c.begin(), c.end());
    int kase = 0;
    while(scanf("%d", &a)) {
      int ans = 0, base = 1;
      REP(i, 0, n) {
        ans += base * c[i];
        base *= a;
      }
      if(kase) printf(" ");
      printf("%d", ans);
      kase++;
      if((ch = getchar()) == '\n') break;
    }
    printf("\n");
  }
  return 0;
}
